#include "Universal.h"
#include "All.h"


#include "Context/GameSettings.h"
#include "Components/WaypointSettings.h"
#include "Components/WaveSpawnSettings.h"

#include "Game.h"


#if UNITY_NATIVE_DLL

void SFetchWorldSettings(Registry& registry)
{
	Entity gameSettingsSingleton = registry.create();
	registry.set<CtxGameSettings>(CtxGameSettings{ gameSettingsSingleton });
	auto unityGameSettings = Game::Get()->GetRawInitialGameState();

	// Waypoint Settings
	{
		std::vector<Waypoint> waypoints;
		for (int i = 0; i < unityGameSettings->waypointCount; i++)
		{
			Waypoint w;
			w.position = Vector3(unityGameSettings->waypoints[i * 4], 0, unityGameSettings->waypoints[i * 4 + 1]);
			w.direction = Vector3(unityGameSettings->waypoints[i * 4 + 2], 0, unityGameSettings->waypoints[i * 4 + 3]);
			waypoints.push_back(w);
		}

		CWaypointSettings waypointSettings;
		waypointSettings.waypoints = waypoints;
		registry.emplace<CWaypointSettings>(gameSettingsSingleton, waypointSettings);
	}

	// Spawn time settings
	{
		std::vector<WaveSpawnConfiguration> waves;
		for (int i = 0; i < unityGameSettings->waveCount; i++)
		{
			waves.push_back(unityGameSettings->waves[i]);
		}

		CWaveSpawnSettings waveSpawnSettings;
		waveSpawnSettings.waves = waves;
		registry.emplace<CWaveSpawnSettings>(gameSettingsSingleton, waveSpawnSettings);
	}
}

#else

void SFetchWorldSettings(Registry& registry)
{
	Entity gameSettingsSingleton = registry.create();
	registry.set<CtxGameSettings>(CtxGameSettings{ gameSettingsSingleton });

	{
		std::vector<Waypoint> waypoints = {
			{ Vector3(0, 0, 0), Vector3(1, 0, 0) },
			{ Vector3(5, 0, 0), Vector3(0, 0, 1) },
			{ Vector3(5, 0, 5), Vector3(1, 0, 0) },
			{ Vector3(10, 0, 5), Vector3(1, 0, 0) },
		};

		CWaypointSettings waypointSettings;
		waypointSettings.waypoints = waypoints;
		registry.emplace<CWaypointSettings>(gameSettingsSingleton, waypointSettings);
	}

	{
		std::vector<WaveSpawnConfiguration> waves;

		CWaveSpawnSettings waveSpawnSettings;
		waveSpawnSettings.waves = waves;
		registry.emplace<CWaveSpawnSettings>(gameSettingsSingleton, waveSpawnSettings);
	}
}

#endif