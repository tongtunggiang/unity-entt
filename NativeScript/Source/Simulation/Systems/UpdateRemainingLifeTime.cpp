#include "Universal.h"
#include "All.h"

#include "Components/LifeTime.h"
#include "Components/RemoveMe.h"

void SUpdateRemainingLifeTime(Registry& registry, float dt)
{
	registry.view<CLifeTime>().each(
		[dt, &registry](auto entity, CLifeTime& lifeTime)
		{
			if (lifeTime.value > 0)
			{
				lifeTime.value -= dt;
				if (lifeTime.value <= 0)
				{
					registry.remove<CLifeTime>(entity);
					registry.emplace<CRemoveMe>(entity);
				}
			}
		}
	);
}
