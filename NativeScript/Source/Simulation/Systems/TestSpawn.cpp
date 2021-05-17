#include "Universal.h"
#include "All.h"

#include "Helpers/SpawnHelpers.h"

void SInitTestSpawn(Registry& registry)
{
	for (int i = 0; i < 1; i++)
		SpawnHelpers::SpawnEnemy(registry);
}
