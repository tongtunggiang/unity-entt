#include "Universal.h"

#include "All.h"

#include "Components/Position.h"
#include "Components/Orientation.h"
#include "Components/Destination.h"
#include "Components/WaypointIndex.h"
#include "Components/WaypointSettings.h"

#include "Context/GameSettings.h"

void SUpdateWaypointMovement(Registry& registry, float deltaTime)
{
	PROFILER_FUNCTION();


	const auto& gameSettingsSingleton = registry.ctx<CtxGameSettings>().holderEntity;
	const auto& waypointSettings = registry.get<CWaypointSettings>(gameSettingsSingleton);
	const std::vector<Waypoint>& waypoints = waypointSettings.waypoints;
	auto& waypointMovementView = registry.group<CWaypointIndex>(entt::get<CPosition, COrientation, CDestination>);
	std::for_each(std::execution::par, 
		waypointMovementView.begin(), waypointMovementView.end(),
		[deltaTime, &waypoints, &waypointMovementView](const auto entity)
		{
			CWaypointIndex& waypointIndex = waypointMovementView.get<CWaypointIndex>(entity);
			CPosition& position = waypointMovementView.get<CPosition>(entity);
			COrientation& orientation = waypointMovementView.get<COrientation>(entity);
			CDestination& destination = waypointMovementView.get<CDestination>(entity);

			Vector3 delta = destination.value - position.value;

			// Move past the destination already
			if (delta.dot(orientation.value) < 0)
			{
				position.value = destination.value;

				if (waypointIndex.value < waypoints.size() - 1)
				{
					orientation.value = waypoints[waypointIndex.value].direction;

					waypointIndex.value++;
					destination.value = waypoints[waypointIndex.value].position;
				}
			}
		});

	PROFILER_END();
}

