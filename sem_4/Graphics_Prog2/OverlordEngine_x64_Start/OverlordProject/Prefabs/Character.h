#pragma once
struct CharacterDesc
{
	CharacterDesc(
		PxMaterial* pMaterial,
		float radius = .5f,
		float height = 2.f)
	{
		controller.setToDefault();
		controller.radius = radius;
		controller.height = height;
		controller.material = pMaterial;
	}

	void CalculateMoveSpeedMultiplier()
	{
		switch (speedLevel)
		{
		case 1:
			speedMultiplier = 1.f;
			break;

		case 2:
			speedMultiplier = 1.25f;
			break;

		case 3:
			speedMultiplier = 1.5f;
			break;

		case 4:
			speedMultiplier = 1.75f;
			break;

		case 5:
			speedMultiplier = 2.f;
			break;

		case 6:
			speedMultiplier = 2.25f;
			break;

		case 7:
			speedMultiplier = 2.5f;
			break;

		case 8:
			speedMultiplier = 2.75f;
			break;

		default:
			speedLevel = 1;
			CalculateMoveSpeedMultiplier();
			break;
		}
	}

	int speedLevel{ 8 };
	float speedMultiplier{ 1.f };
	float maxMoveSpeed{ 5.f };
	float maxFallSpeed{ 15.f };

	bool canJump{ true };
	float JumpSpeed{ 15.f };

	float moveAccelerationTime{ .3f };
	float fallAccelerationTime{ .3f };

	PxCapsuleControllerDesc controller{};

	float rotationSpeed{ 60.f };

	GamepadIndex playerIndex{};
	bool useController{};
	int actionId_MoveLeft{ -1 };
	int actionId_MoveRight{ -1 };
	int actionId_MoveForward{ -1 };
	int actionId_MoveBackward{ -1 };
	int actionId_Jump{ -1 };

	bool lookTowardsWalkDirection{};

	bool useOwnCamera{ true };

	float stepOffset{ 0.5f };

	const int maxAmountOfBombsAllowedToBePlacedAtOnce{ 8 };
	int amountOfBombsAllowedToBePlacedAtOnce{ 3 };
	int amountOfBombsCurrentlyOnGrid{};
	const int maxBombBlastRadius{ 10 };
	int bombBlastRadius{ 5 };
	bool hasPierceBomb{};
};

enum class CharacterAnimationState
{
	none,
	idle,
	running
};

class Character : public GameObject
{
public:
	Character(const CharacterDesc& characterDesc, CharacterAnimationState animationState = CharacterAnimationState::none);
	~Character() override = default;

	Character(const Character& other) = delete;
	Character(Character&& other) noexcept = delete;
	Character& operator=(const Character& other) = delete;
	Character& operator=(Character&& other) noexcept = delete;

	void DrawImGui();
	void SetModelAnimator(ModelAnimator* pModelAnimator) { m_pModelAnimator = pModelAnimator; }
	void SetPChild(GameObject* pChild) { m_pChild = pChild; }
	CharacterDesc& GetCharacterDescription() { return m_CharacterDesc; }

protected:
	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

private:
	CameraComponent* m_pCameraComponent{};
	ControllerComponent* m_pControllerComponent{};
	ModelAnimator* m_pModelAnimator{};

	CharacterAnimationState m_AnimationState{};

	GameObject* m_pChild{}; //the model of the player is in the component of a child because if not the model floats

	CharacterDesc m_CharacterDesc;
	float m_TotalPitch{}, m_TotalYaw{};				//Total camera Pitch(X) and Yaw(Y) rotation
	float m_MoveAcceleration{},						//Acceleration required to reach maxMoveVelocity after 1 second (maxMoveVelocity / moveAccelerationTime)
		m_FallAcceleration{},						//Acceleration required to reach maxFallVelocity after 1 second (maxFallVelocity / fallAccelerationTime)
		m_MoveSpeed{};								//MoveSpeed > Horizontal Velocity = MoveDirection * MoveVelocity (= TotalVelocity.xz)

	XMFLOAT3 m_TotalVelocity{};						//TotalVelocity with X/Z for Horizontal Movement AND Y for Vertical Movement (fall/jump)
	XMFLOAT3 m_CurrentDirection{};					//Current/Last Direction based on Camera forward/right (Stored for deacceleration)
};

