#include "Universal.h"
#include "All.h"

#include "Components/Cooldown.h"

void SUpdateCooldown(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	registry.view<CCooldown>().each(
		[dt, &registry](auto entity, CCooldown& cooldown)
		{
			cooldown.remaining -= dt;
			if (cooldown.remaining <= 0)
			{
				registry.remove<CCooldown>(entity);
			}
		}
	);

	PROFILER_END();
}
