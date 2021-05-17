#include "Universal.h"
#include "CooldownHelpers.h"

#include "Components/Cooldown.h"

void CooldownHelpers::StartCooldown(Registry& registry, Entity entity, float time)
{
	registry.emplace<CCooldown>(entity, CCooldown{ time, time });

#if UNITY_NATIVE_DLL
	// Spawn the HUD view
	{
		using namespace UnityEngine;
		using namespace System;
		using Object = UnityEngine::Object;

		GameObject prefab = Resources::Load<GameObject>(String("Prefabs/EntityCooldownView"));

		GameObject go = Native::UnityTypeHelpers::Downcast<GameObject>(Object::Instantiate((Object)prefab));
		Native::BaseNativeEntityView unityView = go.GetComponent<Native::BaseNativeEntityView>();
		unityView.SetEntityRef((uint32_t)entity);
	}
#endif
}
