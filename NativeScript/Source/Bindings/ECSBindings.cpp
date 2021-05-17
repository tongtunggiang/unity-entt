#if UNITY_NATIVE_DLL

#include "Universal.h"
#include "Game.h"

#include "Helpers/SpawnHelpers.h"

#include "Context/GameStates.h"


/**
 * Bindings listing for C# layers to call, no C++ code should call this
 */


//----------------------------------------------------------------------------------------------------
// Template for auto-gen functions
#define DEFINE_GET_COMPONENT(ComponentType, FuncName)                                               \
ComponentType g_Static ##ComponentType;                                                             \
DLLEXPORT ComponentType FuncName(Entity e)	                                                        \
{																									\
    auto& registry = Game::Get()->GetCurrentWorld()->GetRegistry();                                 \
    if (registry.has<ComponentType>(e))                                                             \
	    return registry.get<ComponentType>(e);					                                    \
    else                                                                                            \
        return g_Static ##ComponentType;                                                            \
}																									\



#define DEFINE_GET_GAME_STATE(StateComponentType, FuncName)                             \
DLLEXPORT StateComponentType FuncName()                                                 \
{                                                                                       \
    auto& registry = Game::Get()->GetCurrentWorld()->GetRegistry();                     \
    const auto& gameStatesSingleton = registry.ctx<CtxGameStates>().holderEntity;       \
    return registry.get<StateComponentType>(gameStatesSingleton);                       \
}                                                                                       \



//----------------------------------------------------------------------------------------------------
// Spawn functions
DLLEXPORT void SpawnTower(float x, float y)
{
	SpawnHelpers::SpawnTower(Game::Get()->GetCurrentWorld()->GetRegistry(),
		x, y);
}



//----------------------------------------------------------------------------------------------------
// Auto generated section


/*BEGIN COMPONENT HEADER INCLUDE*/
#include "Components/BodySize.h"
#include "Components/CollisionLayer.h"
#include "Components/Cooldown.h"
#include "Components/CurrentWave.h"
#include "Components/Damage.h"
#include "Components/Destination.h"
#include "Components/ElapsedTime.h"
#include "Components/Health.h"
#include "Components/LifeTime.h"
#include "Components/MoveSpeed.h"
#include "Components/Orientation.h"
#include "Components/Position.h"
#include "Components/RangeDetection.h"
#include "Components/WaypointIndex.h"
/*END COMPONENT HEADER INCLUDE*/

/*BEGIN GET COMPONENT FUNCTIONS*/
DEFINE_GET_COMPONENT(CBodySize, GetBodySize)
DEFINE_GET_COMPONENT(CCollisionLayer, GetCollisionLayer)
DEFINE_GET_COMPONENT(CCooldown, GetCooldown)
DEFINE_GET_COMPONENT(CDamage, GetDamage)
DEFINE_GET_COMPONENT(CDestination, GetDestination)
DEFINE_GET_COMPONENT(CHealth, GetHealth)
DEFINE_GET_COMPONENT(CLifeTime, GetLifeTime)
DEFINE_GET_COMPONENT(CMoveSpeed, GetMoveSpeed)
DEFINE_GET_COMPONENT(COrientation, GetOrientation)
DEFINE_GET_COMPONENT(CPosition, GetPosition)
DEFINE_GET_COMPONENT(CRangeDetection, GetRangeDetection)
DEFINE_GET_COMPONENT(CWaypointIndex, GetWaypointIndex)
/*END GET COMPONENT FUNCTIONS*/


/*BEGIN GET STATES FUNCTIONS*/
DEFINE_GET_GAME_STATE(CCurrentWave, GetStateCurrentWave)
DEFINE_GET_GAME_STATE(CElapsedTime, GetStateElapsedTime)
/*END GET STATES FUNCTIONS*/

#endif
