#pragma once

#include "World.h"

#include "Components/WaveSpawnSettings.h"

/**
 * Initial game state, passed by Unity to PluginMain()
 */
struct RawInitialGameState
{
	std::int32_t waypointCount;
	float* waypoints;
	std::int32_t waveCount;
	WaveSpawnConfiguration* waves;
};

class Game
{
	// Singleton
public:
	static Game* Get();

	void Init();
	void Update(float deltaTime);

	class World* GetCurrentWorld();

	void SetRawInitialGameState(void* initialGameState);
	const RawInitialGameState* GetRawInitialGameState();

private:
	std::unique_ptr<class World> m_World;
	RawInitialGameState* m_RawInitialGameState;

#if UNITY_NATIVE_DLL

public:
	void SetEventHub(Native::EventHub eventHub);
	Native::EventHub GetEventHub();

private:
	Native::EventHub m_EventHub;
#endif

private:
	Game();
	static Game* s_Instance;

};