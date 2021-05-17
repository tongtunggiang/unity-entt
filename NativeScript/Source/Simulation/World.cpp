#include "Universal.h"
#include "World.h"

#include "Game.h"

#include "Systems/All.h"

constexpr float FixedTimeStep = 0.02f;

World::World()
{
}

World::~World()
{
}

void World::Init()
{
	SFetchWorldSettings(m_Registry);
	SInitWorldState(m_Registry);
}

void World::Update(float deltaTime)
{
	SUpdateWaveSpawn(m_Registry, deltaTime);

	SUpdateMoveForward(m_Registry, deltaTime);
	SUpdateWaypointMovement(m_Registry, deltaTime);

	SUpdateCooldown(m_Registry, deltaTime);
	SUpdateSingleFiring(m_Registry, deltaTime);

	SUpdateQueryCollision(m_Registry, deltaTime);

	SUpdateEntityDie(m_Registry, deltaTime);
	SUpdateRemainingLifeTime(m_Registry, deltaTime);

	SUpdateRemoveEntity(m_Registry, deltaTime);
}
