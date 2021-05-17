#pragma once

namespace SpawnHelpers
{
void SpawnEnemy(Registry& registry);
void SpawnTower(Registry& registry, float posX, float posY);
void SpawnBullet(Registry& registry, Vector3 position, Vector3 orientation);
}
