#include "Universal.h"
#include "All.h"

#include "Context/GameStates.h"

#include "Components/ElapsedTime.h"
#include "Components/CurrentWave.h"


void SInitWorldState(Registry& registry)
{
	Entity gameStatesSingleton = registry.create();
	registry.set<CtxGameStates>(CtxGameStates{ gameStatesSingleton });

	registry.emplace<CElapsedTime>(gameStatesSingleton, CElapsedTime{ 0.0f });
	registry.emplace<CCurrentWave>(gameStatesSingleton, CCurrentWave{ 0, 0, 0 });
}
