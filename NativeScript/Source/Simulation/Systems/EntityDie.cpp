#include "Universal.h"
#include "All.h"

#include "Components/Health.h"
#include "Components/RemoveMe.h"
	
#include "Game.h"

void SUpdateEntityDie(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	registry.view<CHealth>().each(
		[&registry](auto entity, CHealth& health)
		{
			if (health.current <= 0)
			{
				registry.remove<CHealth>(entity);
				registry.emplace<CRemoveMe>(entity);
			}
		}
	);

	PROFILER_END();
}
