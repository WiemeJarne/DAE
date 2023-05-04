#include "stdafx.h"
#include "Character.h"

Character::Character(const CharacterDesc& characterDesc) :
	m_CharacterDesc{ characterDesc },
	m_MoveAcceleration(characterDesc.maxMoveSpeed / characterDesc.moveAccelerationTime),
	m_FallAcceleration(characterDesc.maxFallSpeed / characterDesc.fallAccelerationTime)
{}

void Character::Initialize(const SceneContext& /*sceneContext*/)
{
	//Controller
	m_pControllerComponent = AddComponent(new ControllerComponent(m_CharacterDesc.controller));
	m_pControllerComponent->GetPxController()->setStepOffset(m_CharacterDesc.stepOffset);

	//Camera
	const auto pCamera = AddChild(new FixedCamera());
	m_pCameraComponent = pCamera->GetComponent<CameraComponent>();

	if (m_CharacterDesc.useOwnCamera)
	{
		m_pCameraComponent->SetActive(true); //Uncomment to make this camera the active camera
		pCamera->GetTransform()->Translate(0.f, m_CharacterDesc.controller.height * .5f, 0.f);
	}
}

void Character::Update(const SceneContext& sceneContext)
{
	//constexpr float epsilon{ 0.01f }; //Constant that can be used to compare if a float is near zero
	const float elapsedSec{ sceneContext.pGameTime->GetElapsed() };

	//***************
	//HANDLE INPUT

	//## Input Gathering (move)
	XMFLOAT2 move{};

	if (!m_CharacterDesc.useController)
	{
		//move.y should contain a 1 (Forward) or -1 (Backward) based on the active input (check corresponding actionId in m_CharacterDesc)
		if (sceneContext.pInput->IsActionTriggered(m_CharacterDesc.actionId_MoveForward))
			move.y = 1;
		else if (sceneContext.pInput->IsActionTriggered(m_CharacterDesc.actionId_MoveBackward))
			move.y = -1;
	}
	else
	{
		move.y = sceneContext.pInput->GetThumbstickPosition(true, m_CharacterDesc.playerIndex).y;
	}

	if (!m_CharacterDesc.useController)
	{
		//move.x should contain a 1 (Right) or -1 (Left) based on the active input (check corresponding actionId in m_CharacterDesc)
		if (sceneContext.pInput->IsActionTriggered(m_CharacterDesc.actionId_MoveRight))
			move.x = 1;
		else if (sceneContext.pInput->IsActionTriggered(m_CharacterDesc.actionId_MoveLeft))
			move.x = -1;
	}
	else
	{
		move.x = sceneContext.pInput->GetThumbstickPosition(true, m_CharacterDesc.playerIndex).x;
	}
	
	//## Input Gathering (look)
	XMFLOAT2 look{ 0.f, 0.f }; //Uncomment
	
	if (!m_CharacterDesc.useController)
	{
		//Only if the Left Mouse Button is Down >
		if (sceneContext.pInput->IsMouseButton(InputState::down, 1))
		{
			// Store the MouseMovement in the local 'look' variable (cast is required)
			const auto& mouseMovement{ sceneContext.pInput->GetMouseMovement() };
			look.x = static_cast<float>(mouseMovement.x);
			look.y = static_cast<float>(mouseMovement.y);
		}
	}
	else
	{
		look = sceneContext.pInput->GetThumbstickPosition(false, m_CharacterDesc.playerIndex);
		look.y = -look.y;
	}

	//************************
	//GATHERING TRANSFORM INFO

	//Retrieve the TransformComponent
	const auto transfromComponent{ GetTransform() };

	//Retrieve the forward & right vector (as XMVECTOR) from the TransformComponent
	const auto& forward{ XMLoadFloat3(&transfromComponent->GetForward()) };
	const auto& right{ XMLoadFloat3(&transfromComponent->GetRight()) };

	//***************
	//CAMERA ROTATION
	if (m_CharacterDesc.useOwnCamera && m_pCameraComponent->IsActive())
	{
		//Adjust the TotalYaw (m_TotalYaw) & TotalPitch (m_TotalPitch) based on the local 'look' variable
		//Make sure this calculated on a framerate independent way and uses CharacterDesc::rotationSpeed.
		const float rotationAngle{ sceneContext.pGameTime->GetElapsed() * m_CharacterDesc.rotationSpeed };
		m_TotalYaw += look.x * rotationAngle;
		m_TotalPitch += look.y * rotationAngle;

		//Rotate this character based on the TotalPitch (X) and TotalYaw (Y)
		GetTransform()->Rotate(0.f, m_TotalYaw, 0.f);
		sceneContext.pCamera->GetTransform()->Rotate(m_TotalPitch, 0.f, 0.f);
	}

	//********
	//MOVEMENT

	//## Horizontal Velocity (Forward/Backward/Right/Left)
	//Calculate the current move acceleration for this frame (m_MoveAcceleration * ElapsedTime)
	const float currentMoveAcceleration{ m_MoveAcceleration * elapsedSec };
	//If the character is moving (= input is pressed)
	if (abs(move.x) > 0.f || abs(move.y) > 0.f)
	{
		//Calculate & Store the current direction (m_CurrentDirection) >> based on the forward/right vectors and the pressed input
		const XMVECTOR currentDirection{ right * move.x + forward * move.y };
		XMStoreFloat3(&m_CurrentDirection, currentDirection);

		//Increase the current MoveSpeed with the current Acceleration (m_MoveSpeed)
		m_MoveSpeed += currentMoveAcceleration;

		//Make sure the current MoveSpeed stays below the maximum MoveSpeed (CharacterDesc::maxMoveSpeed)
		m_MoveSpeed = std::min(m_MoveSpeed, m_CharacterDesc.maxMoveSpeed);
	}
	else //Else (character is not moving, or stopped moving)
	{
		//Decrease the current MoveSpeed with the current Acceleration (m_MoveSpeed)
		m_MoveSpeed -= currentMoveAcceleration;

		//Make sure the current MoveSpeed doesn't get smaller than zero
		m_MoveSpeed = std::max(m_MoveSpeed, 0.f);
	}

	//Now we can calculate the Horizontal Velocity which should be stored in m_TotalVelocity.xz
	//Calculate the horizontal velocity (m_CurrentDirection * MoveSpeed)
	//Set the x/z component of m_TotalVelocity (horizontal_velocity x/z)
	//It's important that you don't overwrite the y component of m_TotalVelocity (contains the vertical velocity)
	m_TotalVelocity.x = m_CurrentDirection.x * m_MoveSpeed;
	m_TotalVelocity.z = m_CurrentDirection.z * m_MoveSpeed;

	//## Vertical Movement (Jump/Fall)
	//If the Controller Component is NOT grounded (= freefall)
	if (!(m_pControllerComponent->GetCollisionFlags() & PxControllerCollisionFlag::eCOLLISION_DOWN))
	{
		//Decrease the y component of m_TotalVelocity with a fraction (ElapsedTime) of the Fall Acceleration (m_FallAcceleration)
		m_TotalVelocity.y -= elapsedSec * m_FallAcceleration;

		//Make sure that the minimum speed stays above -CharacterDesc::maxFallSpeed (negative!)
		m_TotalVelocity.y = std::max(m_TotalVelocity.y, -m_CharacterDesc.maxFallSpeed);
	}
	else if (m_CharacterDesc.canJump && sceneContext.pInput->IsActionTriggered(m_CharacterDesc.actionId_Jump)) //Else If the jump action is triggered
	{
		//Set m_TotalVelocity.y equal to CharacterDesc::JumpSpeed
		m_TotalVelocity.y = m_CharacterDesc.JumpSpeed;
	}
	else //Else (=Character is grounded, no input pressed)
	{
		//m_TotalVelocity.y is zero
		m_TotalVelocity.y = 0.f;
	}

	//************
	//DISPLACEMENT

	//The displacement required to move the Character Controller (ControllerComponent::Move) can be calculated using our TotalVelocity (m/s)
	//Calculate the displacement (m) for the current frame and move the ControllerComponent
	const XMFLOAT3 displacement
	{
		m_TotalVelocity.x * elapsedSec,
		m_TotalVelocity.y * elapsedSec,
		m_TotalVelocity.z * elapsedSec
	};

	m_pControllerComponent->Move(displacement);

	//The above is a simple implementation of Movement Dynamics, adjust the code to further improve the movement logic and behaviour.
	//Also, it can be usefull to use a seperate RayCast to check if the character is grounded (more responsive)
}

void Character::DrawImGui()
{
	if (ImGui::CollapsingHeader("Character"))
	{
		ImGui::Text(std::format("Move Speed: {:0.1f} m/s", m_MoveSpeed).c_str());
		ImGui::Text(std::format("Fall Speed: {:0.1f} m/s", m_TotalVelocity.y).c_str());

		ImGui::Text(std::format("Move Acceleration: {:0.1f} m/s2", m_MoveAcceleration).c_str());
		ImGui::Text(std::format("Fall Acceleration: {:0.1f} m/s2", m_FallAcceleration).c_str());

		const float jumpMaxTime = m_CharacterDesc.JumpSpeed / m_FallAcceleration;
		const float jumpMaxHeight = (m_CharacterDesc.JumpSpeed * jumpMaxTime) - (0.5f * (m_FallAcceleration * powf(jumpMaxTime, 2)));
		ImGui::Text(std::format("Jump Height: {:0.1f} m", jumpMaxHeight).c_str());

		ImGui::Dummy({ 0.f,5.f });
		if (ImGui::DragFloat("Max Move Speed (m/s)", &m_CharacterDesc.maxMoveSpeed, 0.1f, 0.f, 0.f, "%.1f") ||
			ImGui::DragFloat("Move Acceleration Time (s)", &m_CharacterDesc.moveAccelerationTime, 0.1f, 0.f, 0.f, "%.1f"))
		{
			m_MoveAcceleration = m_CharacterDesc.maxMoveSpeed / m_CharacterDesc.moveAccelerationTime;
		}

		ImGui::Dummy({ 0.f,5.f });
		if (ImGui::DragFloat("Max Fall Speed (m/s)", &m_CharacterDesc.maxFallSpeed, 0.1f, 0.f, 0.f, "%.1f") ||
			ImGui::DragFloat("Fall Acceleration Time (s)", &m_CharacterDesc.fallAccelerationTime, 0.1f, 0.f, 0.f, "%.1f"))
		{
			m_FallAcceleration = m_CharacterDesc.maxFallSpeed / m_CharacterDesc.fallAccelerationTime;
		}

		ImGui::Dummy({ 0.f,5.f });
		ImGui::DragFloat("Jump Speed", &m_CharacterDesc.JumpSpeed, 0.1f, 0.f, 0.f, "%.1f");
		ImGui::DragFloat("Rotation Speed (deg/s)", &m_CharacterDesc.rotationSpeed, 0.1f, 0.f, 0.f, "%.1f");

		bool isActive = m_pCameraComponent->IsActive();
		if(ImGui::Checkbox("Character Camera", &isActive))
		{
			m_pCameraComponent->SetActive(isActive);
		}
	}
}