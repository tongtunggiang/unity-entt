#include "Universal.h"
#include "All.h"

#include "Components/Cooldown.h"
#include "Components/RangeDetection.h"
#include "Components/EnemyTeam.h"
#include "Components/Position.h"
#include "Components/Health.h"
#include "Components/Damage.h"

#include "Helpers/CooldownHelpers.h"
#include "Helpers/SpawnHelpers.h"

void SUpdateSingleFiring(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	registry.view<CRangeDetection, CPosition, CDamage>(entt::exclude<CCooldown>).each(
		[&registry](auto entity, CRangeDetection& range, const CPosition& myPosition, const CDamage& damage) 
		{
			// #Giang.Todo maybe box2d already have some sort of overlap check?
			// currently using a naive approach
			auto enemies = registry.view<CEnemyTeam, CPosition, CHealth>();
			for (auto enemy : enemies)
			{
				auto& enemyPosition = enemies.get<CPosition>(enemy);
				Vector3 delta = enemyPosition.value - myPosition.value;
				if (delta.squaredNorm() <= range.range * range.range)
				{
					Vector3 bulletPosition = myPosition.value;
					Vector3 bulletOrientation = (enemyPosition.value - myPosition.value).normalized();
					SpawnHelpers::SpawnBullet(registry, bulletPosition, bulletOrientation);

					CooldownHelpers::StartCooldown(registry, entity, 1);
					return;
				}
			}
		}
	);

	PROFILER_END();
}
