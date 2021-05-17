#pragma once


// Initialising functions
void SFetchWorldSettings(Registry& registry);
void SInitWorldState(Registry& registry);
void SInitTestSpawn(Registry& registry);

// Update functions
void SUpdateMoveForward(Registry& registry, float dt);
void SUpdateWaypointMovement(Registry& registry, float dt);
void SUpdateCooldown(Registry& registry, float dt);
void SUpdateSingleFiring(Registry& registry, float dt);
void SUpdateEntityDie(Registry& registry, float dt);
void SUpdateWaveSpawn(Registry& registry, float dt);
void SUpdateQueryCollision(Registry& registry, float dt);
void SUpdateRemainingLifeTime(Registry& registry, float dt);
void SUpdateRemoveEntity(Registry& registry, float dt);
