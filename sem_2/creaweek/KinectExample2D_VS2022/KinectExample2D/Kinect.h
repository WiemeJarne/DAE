#pragma once
#include <NuiApi.h>
#include "utils.h"

class Kinect final
{
public:
	Kinect(float windowWidth, float windowHeight);
	Kinect(const Kinect& other) = delete;
	Kinect& operator=(const Kinect& rhs) = delete;
	Kinect(Kinect&& other) = delete;
	Kinect& operator=(Kinect&& rhs) = delete;
	~Kinect();

	void Update(float elapsedSec);
	void Draw( );
	void ToggleSeatMode( );
	bool IsOverlapping(const Ellipsef ball);
	Circlef GetRightHand( ) const;
	Circlef GetLeftHand( ) const;
	void SetRigtHand(float radius);
	void SetLeftHand(float radius);

private:
	const float m_WindowWidth;
	const float m_WindowHeight;
	float m_JointRadius;
	const float m_PositionRadius;
	const float m_TrackedBoneThickness;
	const float m_InferredBoneThickness;
	const Color4f m_InferredJointColor;
	const Color4f m_TrackedJointColor;
	const Color4f m_InferredBoneColor;
	const Color4f m_TrackedBoneColor;
	const Color4f m_PositionColor;

	Ellipsef RightHand;
	Ellipsef LeftHand;

	bool m_IsSeatedMode;

	// Kinect data
	INuiSensor* m_pNuiSensor;
	HANDLE m_NextSkeletonEventHandle;
	
	// Body tracking information
	NUI_SKELETON_FRAME m_SkeletonFrame;

	// Init kinect
	void InitKinect();
	bool CreateAndInitSensor();
		
	// Get new skeleton data
	void GetNextSkeletonData();

	// Draw a skeleton
	void DrawSkeleton(const NUI_SKELETON_DATA& skel);
	void DrawSkelPosition(const NUI_SKELETON_DATA& skel) const;
	void DrawBones(const NUI_SKELETON_DATA& skel) const;
	void DrawJoints(const NUI_SKELETON_DATA& skel);
	void DrawBone(const NUI_SKELETON_DATA& skel, NUI_SKELETON_POSITION_INDEX bone0, NUI_SKELETON_POSITION_INDEX bone1) const;


	// Convert a skeleton point to screen space
	Point2f SkeletonToScreen(const Vector4& skeletonPosition) const;

   };