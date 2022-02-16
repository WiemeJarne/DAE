#include "pch.h"
#include "Avatar.h"
#include "Level.h"

Avatar::Avatar()
	:m_Shape{50, 280, 36, 97}
	,m_HorSpeed{200.f}
	,m_JumpSpeed{600.f}
	,m_Velocity{0.f, 0.f}
	,m_Acceleration{0.f, -981.f}
	,m_ActionState{ActionState::moving}
	,m_AccuTransformSec{0.f}
	,m_MaxTransformSec{ 1.f }
	,m_Power{ 1 }
{

}