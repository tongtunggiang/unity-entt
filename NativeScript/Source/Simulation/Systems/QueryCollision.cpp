#include "All.h"

#include "Components/Position.h"
#include "Components/BodySize.h"
#include "Components/CollisionLayer.h"

constexpr bool g_CollisionMatrix[ECollisionLayer::ALL][ECollisionLayer::ALL]
{
	{ false, true , },
	{ true , false, }
};

void SUpdateQueryCollision(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	// #Giang.Todo:
	// Use a spatial partitioning solution here.
	auto view = registry.view<CPosition, CBodySize, CCollisionLayer>();
	for (auto e1 : view)
	{
		for (auto e2 : view)
		{
			if (e1 == e2)
				continue;

			const auto& l1 = view.get<CCollisionLayer>(e1);
			const auto& l2 = view.get<CCollisionLayer>(e2);
			if (g_CollisionMatrix[l1.value][l2.value] == false)
				continue;

			const auto& p1 = view.get<CPosition>(e1);
			const auto& p2 = view.get<CPosition>(e2);
			Vector3 difference = p1.value - p2.value;

			const auto& r1 = view.get<CBodySize>(e1);
			const auto& r2 = view.get<CBodySize>(e2);

			if (difference.norm() < (r1.radius + r2.radius))
			{
				char msg[64];
				sprintf(msg, "Entity %d and %d collided", e1, e2);
				UnityEngine::Debug::Log(System::String(msg));
			}
		}
	}

	PROFILER_END();
}
