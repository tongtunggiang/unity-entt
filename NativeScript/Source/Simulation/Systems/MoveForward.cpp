#include "Universal.h"

#include "All.h"

#include "Components/Position.h"
#include "Components/MoveSpeed.h"
#include "Components/Orientation.h"

void SUpdateMoveForward(Registry& registry, float deltaTime)
{
	PROFILER_FUNCTION();

	registry.view<CPosition, COrientation, CMoveSpeed>().each(
		[deltaTime](auto entity, CPosition& position, const COrientation& orientation, const CMoveSpeed& moveSpeed)
		{
			position.value += deltaTime * moveSpeed.value * orientation.value;
		}
	);

	PROFILER_END();
}
