#pragma once

struct WaveSpawnConfiguration
{
	float time;
	int numToSpawn;
	float intervalBetweenSpawn;
};

/* GAME_SETTINGS_COMPONENT */
struct CWaveSpawnSettings
{
	std::vector<WaveSpawnConfiguration> waves;
};
