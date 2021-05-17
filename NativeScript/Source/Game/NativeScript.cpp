#if UNITY_NATIVE_DLL

#include "Universal.h"
#include "NativeScript.h"
#include "Game.h"



void Native::NativeScript::Update()
{
	Game::Get()->Update(UnityEngine::Time::GetDeltaTime());
}

void Native::NativeScript::PassGameConfig(void* config)
{
	Game::Get()->SetRawInitialGameState(config);
}

void Native::NativeScript::StartSimulation()
{
	Game::Get()->SetEventHub(GetEvents());
	Game::Get()->Init();
}

#endif
