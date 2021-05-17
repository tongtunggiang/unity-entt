#include "Universal.h"
#include "SpawnHelpers.h"

#include "Components/Position.h"
#include "Components/MoveSpeed.h"
#include "Components/Destination.h"
#include "Components/Orientation.h"
#include "Components/WaypointIndex.h"
#include "Components/Health.h"
#include "Components/RangeDetection.h"
#include "Components/Damage.h"
#include "Components/EnemyTeam.h"
#include "Components/WaypointSettings.h"
#include "Components/BodySize.h"
#include "Components/LifeTime.h"
#include "Components/CollisionLayer.h"

#include "Context/GameSettings.h"

void SpawnHelpers::SpawnEnemy(Registry& registry)
{

	Entity entity = registry.create();

	registry.emplace<CMoveSpeed>(entity, CMoveSpeed{ 1 });

	const auto& gameSettingsSingleton = registry.ctx<CtxGameSettings>().holderEntity;
	const auto& waypointSettings = registry.get<CWaypointSettings>(gameSettingsSingleton);
	const auto& firstWaypoint = *(waypointSettings.waypoints.begin());
	registry.emplace<CWaypointIndex>(entity, CWaypointIndex{ 0 });
	registry.emplace<COrientation>(entity, COrientation{ firstWaypoint.direction });
	registry.emplace<CDestination>(entity, CDestination{ firstWaypoint.position });
	registry.emplace<CPosition>(entity, CPosition{ firstWaypoint.position });
	registry.emplace<CHealth>(entity, CHealth{ 100, 100 });
	registry.emplace<CBodySize>(entity, CBodySize{ 1 });
	registry.emplace<CEnemyTeam>(entity, CEnemyTeam{});
	registry.emplace<CCollisionLayer>(entity, CCollisionLayer{ ECollisionLayer::Enemy });

#if UNITY_NATIVE_DLL
	using namespace UnityEngine;
	using namespace System;
	using Object = UnityEngine::Object;

	// Spawn the 3D model
	{
		GameObject prefab = Resources::Load<GameObject>(String("Prefabs/EntityView"));

		GameObject go = Native::UnityTypeHelpers::Downcast<GameObject>(Object::Instantiate((Object)prefab));
		Native::BaseNativeEntityView unityView = go.GetComponent<Native::BaseNativeEntityView>();
		unityView.SetEntityRef((uint32_t)entity);
	}

	// Spawn the HUD view
	{
		GameObject prefab = Resources::Load<GameObject>(String("Prefabs/EnemyEntityHealthBarView"));

		GameObject go = Native::UnityTypeHelpers::Downcast<GameObject>(Object::Instantiate((Object)prefab));
		Native::BaseNativeEntityView unityView = go.GetComponent<Native::BaseNativeEntityView>();
		unityView.SetEntityRef((uint32_t)entity);
	}
#endif
}

void SpawnHelpers::SpawnTower(Registry& registry, float posX, float posY)
{
	using Vector3 = ::Vector3;

	Entity entity = registry.create();
	registry.emplace<CPosition>(entity, CPosition{ Vector3(posX, 0, posY) });
	registry.emplace<CRangeDetection>(entity, CRangeDetection{ 5 });
	registry.emplace<CDamage>(entity, CDamage{ 5 });


#if UNITY_NATIVE_DLL
	using namespace UnityEngine;
	using namespace System;
	using Object = UnityEngine::Object;
	// Spawn the 3D model
	{
		GameObject prefab = Resources::Load<GameObject>(String("Prefabs/CannonTowerView"));

		GameObject go = Native::UnityTypeHelpers::Downcast<GameObject>(Object::Instantiate((Object)prefab));
		Native::BaseNativeEntityView unityView = go.GetComponent<Native::BaseNativeEntityView>();
		unityView.SetEntityRef((uint32_t)entity);
	}
#endif
}

void SpawnHelpers::SpawnBullet(Registry& registry, Vector3 position, Vector3 orientation)
{
	Entity entity = registry.create();

	registry.emplace<CMoveSpeed>(entity, CMoveSpeed{ 10 });
	registry.emplace<CPosition>(entity, CPosition{ position });
	registry.emplace<COrientation>(entity, COrientation{ orientation });
	registry.emplace<CBodySize>(entity, CBodySize{ 1.0f });
	registry.emplace<CLifeTime>(entity, CLifeTime{ 2.0f });
	registry.emplace<CCollisionLayer>(entity, CCollisionLayer{ ECollisionLayer::Bullet });

#if UNITY_NATIVE_DLL
	using namespace UnityEngine;
	using namespace System;
	using Object = UnityEngine::Object;
	// Spawn the 3D model
	{
		GameObject prefab = Resources::Load<GameObject>(String("Prefabs/SphereBulletView"));

		GameObject go = Native::UnityTypeHelpers::Downcast<GameObject>(Object::Instantiate((Object)prefab));
		Native::BaseNativeEntityView unityView = go.GetComponent<Native::BaseNativeEntityView>();
		unityView.SetEntityRef((uint32_t)entity);
	}
#endif
}

