#include "stdafx.h"
#include "Plugin.h"
#include "IExamInterface.h"
#include "Behaviors.h"

using namespace std;
using namespace Elite;

//TODO: add bool isPathfindingToHouse in blackboard, add float amountOfTimeFleeing in blackboardss

//Called only once, during initialization
void Plugin::Initialize(IBaseInterface* pInterface, PluginInfo& info)
{
	//Retrieving the interface
	//This interface gives you access to certain actions the AI_Framework can perform for you
	m_pInterface = static_cast<IExamInterface*>(pInterface);

	//fill the list m_lPositionsToVisit with position for the agent to visit
	for (int x{-350 }; x < 350; x += 20)
	{
		for (int y{ -350 }; y < 350; y += 20)
		{
			m_lPositionsToVisit.push_back(Vector2(x, y));
		}
	}
	
	//Create Blackboard
	Elite::Blackboard* pBlackboard{ new Blackboard() };

	//Add data to the Blackboard
	pBlackboard->AddData("SteeringBehaviorType", SteeringBehaviorType::none);
	pBlackboard->AddData("EntitiesInFOV", &m_vEntitiesInFOV);
	pBlackboard->AddData("HousesInFOV", &m_vHousesInFOV);
	pBlackboard->AddData("Interface", m_pInterface);
	pBlackboard->AddData("Target", m_Target);
	pBlackboard->AddData("HousesEntered", &m_vHousesEntered);
	pBlackboard->AddData("posBeforeEnteredHouse", Vector2());
	pBlackboard->AddData("AmountOfTimeInHouse", &m_AmountOfTimeInHouse);
	pBlackboard->AddData("isDoing180", bool());
	pBlackboard->AddData("StartRotationFor180", float());
	pBlackboard->AddData("posItemToSeek", Vector2());
	pBlackboard->AddData("positionsToVisit", &m_lPositionsToVisit);

	//Create BehaviorTree
	m_pBehaviorTree =
	{
		new Elite::BehaviorTree
		(
			pBlackboard,

			new BehaviorSelector
			(
				{
					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsInPergeZone),
							new BehaviorAction(BT_Actions::FleePurgeZoneAgentIsIn)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::NotMaxHealth),
							new BehaviorConditional(BT_Conditions::HasMedkit),
							new BehaviorConditional(BT_Conditions::HasEquipedMedkitHealth),
							new BehaviorAction(BT_Actions::UseMedkit)
						}
					),
					
					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::AlmostOutOfEnergy),
							new BehaviorConditional(BT_Conditions::HasFood),
							new BehaviorConditional(BT_Conditions::HasEquipedFoodEnergy),
							new BehaviorAction(BT_Actions::EatFood)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsEnemyInFOV),

							new BehaviorSelector
							(
								{
									new BehaviorConditional(BT_Conditions::IsNotDoing180),
									new BehaviorAction(BT_Actions::StopRotate180)
								}
							),

							new BehaviorSelector
							(
								{
									new BehaviorSequence
									(
										{
											new BehaviorConditional(BT_Conditions::HasPistol),
											new BehaviorConditional(BT_Conditions::HasEquipedPistolAmmo),
											new BehaviorAction(BT_Actions::FaceEnemy),
											new BehaviorAction(BT_Actions::ShootPistol)
										}
									),
									
									new BehaviorSequence
									(
										{
											new BehaviorConditional(BT_Conditions::HasShotGun),
											new BehaviorConditional(BT_Conditions::HasEquipedShotgunAmmo),
											new BehaviorAction(BT_Actions::FaceEnemy),
											new BehaviorAction(BT_Actions::ShootShotgun)
										}
									),

									new BehaviorSequence
									(
										{
											new BehaviorConditional(BT_Conditions::CanSprint),
											new BehaviorAction(BT_Actions::ChangeToSprintFlee)
										}
									),
									
									new BehaviorAction(BT_Actions::ChangeToFlee)
								}
							)
						}
					),

					new BehaviorSelector
					(
						{
							new BehaviorSequence
							(
								{
									new BehaviorConditional(BT_Conditions::HasTakenDamage),
									new BehaviorAction(BT_Actions::Rotate180)
								}
							),

							new BehaviorSequence
							(
								{
									new BehaviorConditional(BT_Conditions::IsDoing180),
									new BehaviorAction(BT_Actions::Rotate180)
								}
							)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsItemInGrabrange),
							
							new BehaviorSelector
							(
								{
									new BehaviorSequence
									(
										{
											new BehaviorConditional(BT_Conditions::IsGarbageInGrabRange),
											new BehaviorAction(BT_Actions::DestroyGarbage)
										}
									),

									new BehaviorSelector
									(
										{
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsPistolInGrabRange),
													new BehaviorConditional(BT_Conditions::HasPistol),
													new BehaviorConditional(BT_Conditions::HasEquipedPistolMoreAmmoThenPistolInGrabrange),
													new BehaviorAction(BT_Actions::DestroyPistolInGrabrange)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsPistolInGrabRange),
													new BehaviorConditional(BT_Conditions::HasPistol),
													new BehaviorAction(BT_Actions::DestroyEquipedPistol)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsPistolInGrabRange),
													new BehaviorAction(BT_Actions::GrabPistol)
												}
											)
										}
									),

									new BehaviorSelector
									(
										{
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsShotgunInGrabRange),
													new BehaviorConditional(BT_Conditions::HasShotGun),
													new BehaviorConditional(BT_Conditions::HasEquipedShotgunMoreAmmoThenShotgunInGrabrange),
													new BehaviorAction(BT_Actions::DestroyPistolInGrabrange)
												}
											),
											
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsShotgunInGrabRange),
													new BehaviorConditional(BT_Conditions::HasShotGun),
													new BehaviorAction(BT_Actions::DestroyEquipedShotgun)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsShotgunInGrabRange),
													new BehaviorAction(BT_Actions::GrabShotGun)
												}
											)
										}
									),

									new BehaviorSelector
									(
										{
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsMedkitInGrabRange),
													new BehaviorConditional(BT_Conditions::HasMedkit),
													new BehaviorConditional(BT_Conditions::HasEquipedMedkitMoreHPThenMedkitInGrabrange),
													new BehaviorAction(BT_Actions::DestroyMedkitInGrabrange)
												}
											),
											
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsMedkitInGrabRange),
													new BehaviorConditional(BT_Conditions::HasMedkit),
													new BehaviorAction(BT_Actions::DestroyEquipedMedkit)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsMedkitInGrabRange),
													new BehaviorAction(BT_Actions::GrabMedkit)
												}
											)
										}
									),

									new BehaviorSelector
									(
										{
											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsFoodInGrabRange),
													new BehaviorConditional(BT_Conditions::HasFood),
													new BehaviorConditional(BT_Conditions::HasEquipedFoodMoreEnergyThenFoodInGrabrange),
													new BehaviorAction(BT_Actions::DestroyFoodInGrabrange)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsFoodInGrabRange),
													new BehaviorConditional(BT_Conditions::HasFood),
													new BehaviorAction(BT_Actions::DestroyEquipedFood)
												}
											),

											new BehaviorSequence
											(
												{
													new BehaviorConditional(BT_Conditions::IsFoodInGrabRange),
													new BehaviorAction(BT_Actions::GrabFood)
												}
											)
										}
									)
								}
							)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsHouseInFOV),
							new BehaviorConditional(BT_Conditions::HasNotEnteredHouseInFOVInlast30Sec),
							new BehaviorAction(BT_Actions::GoInHouse)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsInHouse),
							new BehaviorConditional(BT_Conditions::HasBeenInHouseFor5Seconds),
							new BehaviorAction(BT_Actions::GoOutHouse)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsItemInFOV),
							new BehaviorAction(BT_Actions::SeekLoot)
						}
					),

					new BehaviorSequence
					(
						{
							new BehaviorConditional(BT_Conditions::IsOutside),
							new BehaviorConditional(BT_Conditions::HasNotExploreFullWorld),
							new BehaviorAction(BT_Actions::GoToNextPosToVisit)
						}
					),

					new BehaviorAction(BT_Actions::ChangeToWander)
				}
			)
		)
	};

	//Bit information about the plugin
	//Please fill this in!!
	info.BotName = "MinionExam";
	info.Student_FirstName = "Jarne";
	info.Student_LastName = "Wieme";
	info.Student_Class = "2DAE15";
}

//Called only once
void Plugin::DllInit()
{
	//Called when the plugin is loaded

	//create the steeringBehaviors
	m_pWander = new Wander();
	m_pFace = new Face();
	m_pSeek = new Seek();
	m_pFlee = new Flee();
	m_pSprintFlee = new SprintFlee();
}

//Called only once
void Plugin::DllShutdown()
{
	//Called wheb the plugin gets unloaded
	SAFE_DELETE(m_pBehaviorTree);
	SAFE_DELETE(m_pWander);
}

//Called only once, during initialization
void Plugin::InitGameDebugParams(GameDebugParams& params)
{
	params.AutoFollowCam = true; //Automatically follow the AI? (Default = true)
	params.RenderUI = true; //Render the IMGUI Panel? (Default = true)
	params.SpawnEnemies = true; //Do you want to spawn enemies? (Default = true)
	params.EnemyCount = 20; //How many enemies? (Default = 20)
	params.GodMode = false; //GodMode > You can't die, can be useful to inspect certain behaviors (Default = false)
	params.LevelFile = "GameLevel.gppl";
	params.AutoGrabClosestItem = true; //A call to Item_Grab(...) returns the closest item that can be grabbed. (EntityInfo argument is ignored)
	params.StartingDifficultyStage = 1;
	params.InfiniteStamina = false;
	params.SpawnDebugPistol = true;
	params.SpawnDebugShotgun = true;
	params.SpawnPurgeZonesOnMiddleClick = true;
	params.PrintDebugMessages = true;
	params.ShowDebugItemNames = true;
	params.Seed = 36;
}

//Only Active in DEBUG Mode
//(=Use only for Debug Purposes)
void Plugin::Update(float dt)
{
	//for (const auto& pos : m_lPositionsToVisit)
	//{
	//	m_pInterface->Draw_Point(pos, 1, Vector3(1.f, 1.f, 1.f));
	//}

	//Demo Event Code
	//In the end your AI should be able to walk around without external input
	if (m_pInterface->Input_IsMouseButtonUp(Elite::InputMouseButton::eLeft))
	{
		//Update target based on input
		Elite::MouseData mouseData = m_pInterface->Input_GetMouseData(Elite::InputType::eMouseButton, Elite::InputMouseButton::eLeft);
		const Elite::Vector2 pos = Elite::Vector2(static_cast<float>(mouseData.X), static_cast<float>(mouseData.Y));
		m_Target = m_pInterface->Debug_ConvertScreenToWorld(pos);
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_Space))
	{
		m_CanRun = true;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_Left))
	{
		m_AngSpeed -= Elite::ToRadians(10);
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_Right))
	{
		m_AngSpeed += Elite::ToRadians(10);
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_G))
	{
		m_GrabItem = true;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_U))
	{
		m_UseItem = true;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_R))
	{
		m_RemoveItem = true;
	}
	else if (m_pInterface->Input_IsKeyboardKeyUp(Elite::eScancode_Space))
	{
		m_CanRun = false;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_Delete))
	{
		m_pInterface->RequestShutdown();
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_KP_Minus))
	{
		if (m_InventorySlot > 0)
			--m_InventorySlot;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_KP_Plus))
	{
		if (m_InventorySlot < 4)
			++m_InventorySlot;
	}
	else if (m_pInterface->Input_IsKeyboardKeyDown(Elite::eScancode_Q))
	{
		ItemInfo info = {};
		m_pInterface->Inventory_GetItem(m_InventorySlot, info);
		std::cout << (int)info.Type << std::endl;
	}

	if (m_pInterface->Agent_GetInfo().IsInHouse)
	{
		m_AmountOfTimeInHouse += dt;
	}
	else
	{
		m_AmountOfTimeInHouse = 0.f;
	}

	//remove the position where the agent is the closest to
	for (const auto& pos : m_lPositionsToVisit)
	{
		if (pos.x - m_pInterface->Agent_GetInfo().FOV_Range <= m_pInterface->Agent_GetInfo().Position.x && pos.x + m_pInterface->Agent_GetInfo().FOV_Range >= m_pInterface->Agent_GetInfo().Position.x
			&& pos.y - m_pInterface->Agent_GetInfo().FOV_Range <= m_pInterface->Agent_GetInfo().Position.y && pos.y + m_pInterface->Agent_GetInfo().FOV_Range >= m_pInterface->Agent_GetInfo().Position.y)
		{
			m_lPositionsToVisit.remove(pos);
			break;
		}
	}
}

//Update
//This function calculates the new SteeringOutput, called once per frame
SteeringPlugin_Output Plugin::UpdateSteering(float dt)
{	
	assert(m_pBehaviorTree && "m_pBehaviorTree is null");

	m_pBehaviorTree->Update(dt);

	m_vEntitiesInFOV = GetEntitiesInFOV();
	m_vHousesInFOV = GetHousesInFOV();

	//return m_BehaviorTree->GetSteeringOutput();

	auto steering = SteeringPlugin_Output();
	
	//Use the Interface (IAssignmentInterface) to 'interface' with the AI_Framework
	auto agentInfo = m_pInterface->Agent_GetInfo();

	SteeringBehaviorType steeringBehaviorType;
	if (m_pBehaviorTree->GetBlackboard()->GetData("SteeringBehaviorType", steeringBehaviorType))
	{
		Vector2 target;

		switch (steeringBehaviorType)
		{
		case SteeringBehaviorType::none:
			m_pSteeringBehavior = nullptr;
			break;

		case SteeringBehaviorType::wander:
			m_pSteeringBehavior = m_pWander;
			break;

		case SteeringBehaviorType::face:
			m_pSteeringBehavior = m_pFace;
			m_pBehaviorTree->GetBlackboard()->GetData("Target", target);
			m_pFace->SetTarget(target);
			break;

		case SteeringBehaviorType::seek:
			m_pSteeringBehavior = m_pSeek;
			m_pBehaviorTree->GetBlackboard()->GetData("Target", target);
			m_pSeek->SetTarget(target);
			break;

		case SteeringBehaviorType::flee:
			m_pSteeringBehavior = m_pFlee;
			m_pBehaviorTree->GetBlackboard()->GetData("Target", target);
			m_pFlee->SetTarget(target);
			break;

		case SteeringBehaviorType::sprintFlee:
			m_pSteeringBehavior = m_pSprintFlee;
			m_pBehaviorTree->GetBlackboard()->GetData("Target", target);
			m_pSprintFlee->SetTarget(target);
			break;
		}
	}

	SteeringBehaviorType steeringb;
	m_pBehaviorTree->GetBlackboard()->GetData("SteeringBehaviorType", steeringb);
	if(m_pSteeringBehavior  /*&& steeringb == SteeringBehaviorType::seek*/ )
	return m_pSteeringBehavior->CalculateSteering(dt, agentInfo);

	//Use the navmesh to calculate the next navmesh point
	//auto nextTargetPos = m_pInterface->NavMesh_GetClosestPathPoint(checkpointLocation);

	//OR, Use the mouse target
	auto nextTargetPos = m_pInterface->NavMesh_GetClosestPathPoint(m_Target); //Uncomment this to use mouse position as guidance

	auto vHousesInFOV = GetHousesInFOV();//uses m_pInterface->Fov_GetHouseByIndex(...)
	auto vEntitiesInFOV = GetEntitiesInFOV(); //uses m_pInterface->Fov_GetEntityByIndex(...)

	for (auto& e : vEntitiesInFOV)
	{
		if (e.Type == eEntityType::PURGEZONE)
		{
			PurgeZoneInfo zoneInfo;
			m_pInterface->PurgeZone_GetInfo(e, zoneInfo);
			//std::cout << "Purge Zone in FOV:" << e.Location.x << ", "<< e.Location.y << "---Radius: "<< zoneInfo.Radius << std::endl;
		}
	}

	//INVENTORY USAGE DEMO
	//********************

	if (m_GrabItem)
	{
		ItemInfo item;
		//Item_Grab > When DebugParams.AutoGrabClosestItem is TRUE, the Item_Grab function returns the closest item in range
		//Keep in mind that DebugParams are only used for debugging purposes, by default this flag is FALSE
		//Otherwise, use GetEntitiesInFOV() to retrieve a vector of all entities in the FOV (EntityInfo)
		//Item_Grab gives you the ItemInfo back, based on the passed EntityHash (retrieved by GetEntitiesInFOV)
		if (m_pInterface->Item_Grab({}, item))
		{
			//Once grabbed, you can add it to a specific inventory slot
			//Slot must be empty
			m_pInterface->Inventory_AddItem(m_InventorySlot, item);
		}
	}

	if (m_UseItem)
	{
		//Use an item (make sure there is an item at the given inventory slot)
		m_pInterface->Inventory_UseItem(m_InventorySlot);
	}

	if (m_RemoveItem)
	{
		//Remove an item from a inventory slot
		m_pInterface->Inventory_RemoveItem(m_InventorySlot);
	}

	//Simple Seek Behaviour (towards Target)
	steering.LinearVelocity = nextTargetPos - agentInfo.Position; //Desired Velocity
	steering.LinearVelocity.Normalize(); //Normalize Desired Velocity
	steering.LinearVelocity *= agentInfo.MaxLinearSpeed; //Rescale to Max Speed

	if (Distance(nextTargetPos, agentInfo.Position) < 2.f)
	{
		steering.LinearVelocity = Elite::ZeroVector2;
	}

	//steering.AngularVelocity = m_AngSpeed; //Rotate your character to inspect the world while walking
	steering.AutoOrient = true; //Setting AutoOrient to TRue overrides the AngularVelocity

	steering.RunMode = m_CanRun; //If RunMode is True > MaxLinSpd is increased for a limited time (till your stamina runs out)

	//SteeringPlugin_Output is works the exact same way a SteeringBehaviour output

//@End (Demo Purposes)
	m_GrabItem = false; //Reset State
	m_UseItem = false;
	m_RemoveItem = false;

	return steering;
}

//This function should only be used for rendering debug elements
void Plugin::Render(float dt) const
{
	//This Render function should only contain calls to Interface->Draw_... functions
	m_pInterface->Draw_SolidCircle(m_Target, .7f, { 0,0 }, { 1, 0, 0 });
}

vector<HouseInfo> Plugin::GetHousesInFOV() const
{
	vector<HouseInfo> vHousesInFOV = {};

	HouseInfo hi = {};
	for (int i = 0;; ++i)
	{
		if (m_pInterface->Fov_GetHouseByIndex(i, hi))
		{
			vHousesInFOV.push_back(hi);
			continue;
		}

		break;
	}

	return vHousesInFOV;
}

vector<EntityInfo> Plugin::GetEntitiesInFOV() const
{
	vector<EntityInfo> vEntitiesInFOV = {};

	EntityInfo ei = {};
	for (int i = 0;; ++i)
	{
		if (m_pInterface->Fov_GetEntityByIndex(i, ei))
		{
			vEntitiesInFOV.push_back(ei);
			continue;
		}

		break;
	}

	return vEntitiesInFOV;
}