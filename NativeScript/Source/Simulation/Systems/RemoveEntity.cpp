#include "Universal.h"
#include "All.h"

#include "Game.h"

#include "Components/RemoveMe.h"


void SUpdateRemoveEntity(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	auto toRemoveView = registry.view<CRemoveMe>();
	for (auto toRemoveEntity : toRemoveView)
	{
#if UNITY_NATIVE_DLL
		Game::Get()->GetEventHub().InvokeEntityDestroyed((uint32_t)toRemoveEntity);
#endif
		registry.destroy(toRemoveEntity);
	}

	PROFILER_END();
}


