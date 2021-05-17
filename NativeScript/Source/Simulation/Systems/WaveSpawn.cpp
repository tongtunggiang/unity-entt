#include "Universal.h"
#include "All.h"

#include "Context/GameStates.h"
#include "Context/GameSettings.h"

#include "Helpers/SpawnHelpers.h"

#include "Components/ElapsedTime.h"
#include "Components/WaveSpawnSettings.h"
#include "Components/CurrentWave.h"

void SUpdateWaveSpawn(Registry& registry, float dt)
{
	PROFILER_FUNCTION();

	const auto& gameStatesSingleton = registry.ctx<CtxGameStates>().holderEntity;

	{
		CElapsedTime& elapsed = registry.get<CElapsedTime>(gameStatesSingleton);
		elapsed.value += dt;
	}

	CCurrentWave& waveStatus = registry.get<CCurrentWave>(gameStatesSingleton);
	const CElapsedTime& elapsed = registry.get<CElapsedTime>(gameStatesSingleton);

	const auto& gameSettingsSingleton = registry.ctx<CtxGameSettings>().holderEntity;
	const auto& waves = registry.get<CWaveSpawnSettings>(gameSettingsSingleton).waves;

	if (waveStatus.nextWaveIndex < waves.size() &&
		elapsed.value > waves[waveStatus.nextWaveIndex].time)
	{
		waveStatus.nextWaveIndex++;
		waveStatus.numSpawnedInWave = 0;
		waveStatus.lastSpawnInWave = 0.0f;
	}

	if (waveStatus.nextWaveIndex > 0)
	{
		int currentWaveIndex = waveStatus.nextWaveIndex - 1;
		const auto& spawnConfig = waves[currentWaveIndex];
		if (waveStatus.numSpawnedInWave < spawnConfig.numToSpawn &&
			elapsed.value - waveStatus.lastSpawnInWave >= spawnConfig.intervalBetweenSpawn)
		{
			SpawnHelpers::SpawnEnemy(registry);

			waveStatus.lastSpawnInWave = elapsed.value;
			waveStatus.numSpawnedInWave++;
		}
	}

	PROFILER_END();
}
