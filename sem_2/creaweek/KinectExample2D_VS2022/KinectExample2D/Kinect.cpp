#include "pch.h"
#include "Kinect.h"
#include "utils.h"
#pragma comment (lib, "Kinect10.lib")

Kinect::Kinect(float windowWidth, float windowHeight)
	: m_WindowWidth{ windowWidth }
	, m_WindowHeight{ windowHeight }
	, m_JointRadius{ 3.0f }
	, m_PositionRadius{ 10.0f }
	, m_TrackedBoneThickness{ 1.0f }
	, m_InferredBoneThickness{ 1.0f }
	, m_IsSeatedMode{ true }
	, m_pNuiSensor{ nullptr }
	, m_NextSkeletonEventHandle{ }
	, m_SkeletonFrame{ }
	, m_InferredJointColor{ 1.f, 1.f, 0.f, 1.f }
	, m_TrackedJointColor{ 0.f, 1.f, 0.f, 1.f }
	, m_InferredBoneColor{ 0.5f, 0.5f, 0.5f, 0.5f }
	, m_TrackedBoneColor{ 0.f, 1.f, 0.f, 1.f }
	, m_PositionColor{ 0.f,0.0f,1.0f,1.f }

{
	InitKinect( );
}

Kinect::~Kinect( )
{
	// Turn the kinect off
	if (m_pNuiSensor != nullptr)
	{
		m_pNuiSensor->Release();
		m_pNuiSensor->NuiShutdown();
	}

	if (m_NextSkeletonEventHandle && (m_NextSkeletonEventHandle != INVALID_HANDLE_VALUE))
	{
		CloseHandle(m_NextSkeletonEventHandle);
	}
}

void Kinect::Update(float elapsedSec)
{
	GetNextSkeletonData( );
}

void Kinect::Draw()
{
	for (int skeletonIdx = 0; skeletonIdx < NUI_SKELETON_COUNT; ++skeletonIdx)
	{
		const NUI_SKELETON_DATA& skel = m_SkeletonFrame.SkeletonData[skeletonIdx];
		NUI_SKELETON_TRACKING_STATE trackingState = skel.eTrackingState;
		switch (trackingState)
		{
		case NUI_SKELETON_TRACKED:
			//std::cout << "\nSkeleton " << skeletonIdx << " is tracked";
			DrawSkeleton(skel);
			break;
		case NUI_SKELETON_POSITION_ONLY:
			DrawSkelPosition(skel);
			break;
		case NUI_SKELETON_NOT_TRACKED:
			// do nothing
			break;
		}
	}
}

void Kinect::ToggleSeatMode()
{
	// The 10 lower-body joints of a skeleton will not be tracked if seated mode
	m_IsSeatedMode = !m_IsSeatedMode;

	// Set seated mode for sensor based on our internal state
	m_pNuiSensor->NuiSkeletonTrackingEnable(m_NextSkeletonEventHandle, m_IsSeatedMode ? NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT : 0);

}

void Kinect::GetNextSkeletonData()
{
	// Wait until the m_NextSkeletonEventHandle object is in the signaled state 
	DWORD waitResult = WaitForSingleObject(m_NextSkeletonEventHandle, 0);
	if (waitResult == WAIT_OBJECT_0)
	{
		// Get the next frame of data from the skeleton stream.
		HRESULT hr = m_pNuiSensor->NuiSkeletonGetNextFrame(0, &m_SkeletonFrame);
		if (hr == S_OK)
		{
			// Filter skeleton positions to reduce jitter between frames.
			m_pNuiSensor->NuiTransformSmooth(&m_SkeletonFrame, NULL);
		}
	}
}

void Kinect::DrawSkeleton(const NUI_SKELETON_DATA& skel)
{
		DrawBones(skel);
		DrawJoints(skel);
}

void Kinect::DrawSkelPosition(const NUI_SKELETON_DATA& skel) const
{
	// We've only received the center point of the skeleton, draw that
	utils::SetColor(m_PositionColor);
	utils::DrawEllipse(SkeletonToScreen(skel.Position), m_PositionRadius, m_PositionRadius);
}

void Kinect::DrawBones(const NUI_SKELETON_DATA& skel) const
{
	// Render Torso
	DrawBone(skel, NUI_SKELETON_POSITION_HEAD, NUI_SKELETON_POSITION_SHOULDER_CENTER);
	DrawBone(skel, NUI_SKELETON_POSITION_SHOULDER_CENTER, NUI_SKELETON_POSITION_SHOULDER_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_SHOULDER_CENTER, NUI_SKELETON_POSITION_SHOULDER_RIGHT);
	DrawBone(skel, NUI_SKELETON_POSITION_SHOULDER_CENTER, NUI_SKELETON_POSITION_SPINE);
	DrawBone(skel, NUI_SKELETON_POSITION_SPINE, NUI_SKELETON_POSITION_HIP_CENTER);
	DrawBone(skel, NUI_SKELETON_POSITION_HIP_CENTER, NUI_SKELETON_POSITION_HIP_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_HIP_CENTER, NUI_SKELETON_POSITION_HIP_RIGHT);

	// Left Arm
	DrawBone(skel, NUI_SKELETON_POSITION_SHOULDER_LEFT, NUI_SKELETON_POSITION_ELBOW_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_ELBOW_LEFT, NUI_SKELETON_POSITION_WRIST_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_WRIST_LEFT, NUI_SKELETON_POSITION_HAND_LEFT);

	// Right Arm
	DrawBone(skel, NUI_SKELETON_POSITION_SHOULDER_RIGHT, NUI_SKELETON_POSITION_ELBOW_RIGHT);
	DrawBone(skel, NUI_SKELETON_POSITION_ELBOW_RIGHT, NUI_SKELETON_POSITION_WRIST_RIGHT);
	DrawBone(skel, NUI_SKELETON_POSITION_WRIST_RIGHT, NUI_SKELETON_POSITION_HAND_RIGHT);

	// Left Leg
	DrawBone(skel, NUI_SKELETON_POSITION_HIP_LEFT, NUI_SKELETON_POSITION_KNEE_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_KNEE_LEFT, NUI_SKELETON_POSITION_ANKLE_LEFT);
	DrawBone(skel, NUI_SKELETON_POSITION_ANKLE_LEFT, NUI_SKELETON_POSITION_FOOT_LEFT);

	// Right Leg
	DrawBone(skel, NUI_SKELETON_POSITION_HIP_RIGHT, NUI_SKELETON_POSITION_KNEE_RIGHT);
	DrawBone(skel, NUI_SKELETON_POSITION_KNEE_RIGHT, NUI_SKELETON_POSITION_ANKLE_RIGHT);
	DrawBone(skel, NUI_SKELETON_POSITION_ANKLE_RIGHT, NUI_SKELETON_POSITION_FOOT_RIGHT);
}

void Kinect::DrawJoints(const NUI_SKELETON_DATA& skel)
{
	// Draw all the joints
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; ++i)
	{
		Point2f pos{};
		switch (skel.eSkeletonPositionTrackingState[i])
		{
		case NUI_SKELETON_POSITION_INFERRED:
			utils::SetColor(m_InferredJointColor);
			pos = SkeletonToScreen(skel.SkeletonPositions[i]);
			utils::DrawEllipse(pos, m_JointRadius, m_JointRadius);
			break;
		case NUI_SKELETON_POSITION_TRACKED:
			utils::SetColor(m_TrackedJointColor);
			pos = SkeletonToScreen(skel.SkeletonPositions[i]);

			if (i == 11)
			{
				RightHand = Ellipsef{ pos, 20.f, 20.f };

				utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
				utils::FillEllipse(RightHand);
			}
			else if(i == 7)
			{
				LeftHand = Ellipsef{ pos, 20.f, 20.f };

				utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
				utils::FillEllipse(LeftHand);
			}
			else
			{
				utils::DrawEllipse(pos, m_JointRadius, m_JointRadius);
			}
			break;
		case NUI_SKELETON_POSITION_NOT_TRACKED:
			// do nothing
			break;
		}
	}
}

void Kinect::DrawBone(const NUI_SKELETON_DATA& skel, NUI_SKELETON_POSITION_INDEX joint0, NUI_SKELETON_POSITION_INDEX joint1) const
{
	NUI_SKELETON_POSITION_TRACKING_STATE joint0State = skel.eSkeletonPositionTrackingState[joint0];
	NUI_SKELETON_POSITION_TRACKING_STATE joint1State = skel.eSkeletonPositionTrackingState[joint1];

	// One of the points is not tracked, so return
	if (joint0State == NUI_SKELETON_POSITION_NOT_TRACKED || joint1State == NUI_SKELETON_POSITION_NOT_TRACKED)
	{
		return;
	}

	// Don't draw if both points are inferred
	if (joint0State == NUI_SKELETON_POSITION_INFERRED && joint1State == NUI_SKELETON_POSITION_INFERRED)
	{
		return;
	}

	// We assume all drawn bones are inferred unless BOTH joints are tracked
	Color4f boneColor{ m_InferredBoneColor };
	float boneThickness{ m_InferredBoneThickness };
	if (joint0State == NUI_SKELETON_POSITION_TRACKED && joint1State == NUI_SKELETON_POSITION_TRACKED)
	{
		boneColor = m_TrackedBoneColor;
		boneThickness = m_TrackedBoneThickness;
	}

	// Draw the bone
	utils::SetColor(boneColor);
	Point2f joint0Pos{ SkeletonToScreen(skel.SkeletonPositions[joint0]) };
	Point2f joint1Pos{ SkeletonToScreen(skel.SkeletonPositions[joint1]) };
	utils::DrawLine(joint0Pos, joint1Pos, boneThickness);
}


Point2f Kinect::SkeletonToScreen(const Vector4& skeletonPosition) const
{
	// Calculate the skeleton's position on the screen
	FLOAT x, y;
	NuiTransformSkeletonToDepthImage(skeletonPosition, &x, &y, NUI_IMAGE_RESOLUTION_640x480);
	float screenPointX = (x * m_WindowWidth) / 640;
	float screenPointY = (y * m_WindowHeight) / 480;

	return Point2f{ screenPointX, m_WindowHeight - screenPointY };
}

void Kinect::InitKinect()
{
	// If not intialized, initialize
	while (CreateAndInitSensor() == false)
	{
		// Just wait a little before next attempt to connect 
		Sleep(1000);
	}
}

bool Kinect::CreateAndInitSensor()
{
	// Get a working Kinect sensor
	std::cout << "\nTrying to connect...";

	int nrSensors{ 0 };
	HRESULT hr = NuiGetSensorCount(&nrSensors);
	if (hr != S_OK)
	{
		std::cerr << "NuiGetSensorCount: Failed to get sensor count.";
		return false;
	}
	if (nrSensors == 0)
	{
		std::cerr << "No sensors found.\n";
		return false;
	}
	else
	{
		std::cout << nrSensors << " sensors found.\n";
	}

	// Try to create a sensor 
	for (int i = 0; i < nrSensors && m_pNuiSensor == nullptr; ++i)
	{
		// Create the sensor so we can check status, 
		// if we can't create it, move on to the next one
		INuiSensor* pNuiSensor;
		hr = NuiCreateSensorByIndex(i, &pNuiSensor);
		if (hr == S_OK)
		{
			// Get the status of the sensor, 
			// and if connected, then we can initialize it
			hr = pNuiSensor->NuiStatus();
			if (hr == S_OK)
			{
				m_pNuiSensor = pNuiSensor;
			}
			// This sensor wasn't OK, so release it since we're not using it
			else
			{
				pNuiSensor->Release();
			}
		}
	}

	if (!m_pNuiSensor)
	{
		std::cerr << "\nNuiCreateSensorByIndex or NuiStatus: No activated kinect sensor found!";
		return false;
	}

	std::cout << "\nConnected to a sensor";
	std::cout << "\nInitializing the sensor to provide skeleton data ...";

	// Initialize the Kinect and specify that we'll want skeleton tracking
	hr = m_pNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	if (hr != S_OK)
	{
		std::cerr << "\nNuiInitialize: Failed to initialize the sensor to provide skeleton data.";
		m_pNuiSensor->Release();
		return false;
	}
	std::cout << " was succesfull.\n";

	// Create an unnamed event object that will be signaled when skeleton data is available
	m_NextSkeletonEventHandle = CreateEventW(NULL, TRUE, FALSE, NULL);
	if (m_NextSkeletonEventHandle == NULL)
	{
		std::cerr << "\nCreateEventW: Failed to create an event object.";
		m_pNuiSensor->Release();
		return false;
	}

	// Open a skeleton stream to receive skeleton data
	hr = m_pNuiSensor->NuiSkeletonTrackingEnable(m_NextSkeletonEventHandle, m_IsSeatedMode ? NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT : 0);
	if (hr != S_OK)
	{
		std::cerr << "\nNuiSkeletonTrackingEnable: Failed to enable skeleton tracking.";
		m_pNuiSensor->Release();
		return false;
	}
	std::cout << "Kinect init succeeded.";
	return true;
}

bool Kinect::IsOverlapping(const Ellipsef ball)
{
	Circlef ballCircle{ ball.center, ball.radiusX };
	Circlef leftHandCircle{ LeftHand.center, LeftHand.radiusX };
	Circlef rightHandCircle{ RightHand.center, RightHand.radiusX };

	if (utils::IsOverlapping(ballCircle, leftHandCircle) || utils::IsOverlapping(ballCircle, rightHandCircle))
	{
		return true;
	}
	
	return false;
}

Circlef Kinect::GetRightHand( ) const
{
	Circlef rightHand{ RightHand.center, RightHand.radiusX };

	return rightHand;
}

Circlef Kinect::GetLeftHand( ) const
{
	Circlef leftHand{ LeftHand.center, LeftHand.radiusX };

	return leftHand;
}

void Kinect::SetRigtHand(float radius)
{
	RightHand.radiusX += radius;
	RightHand.radiusY += radius;
}

void Kinect::SetLeftHand(float radius)
{
	LeftHand.radiusX += radius;
	LeftHand.radiusY += radius;
}