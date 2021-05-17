#include "Universal.h"
#include "Game.h"

#if UNITY_NATIVE_DLL

// Called when the plugin is initialized
// This is mostly full of test code. Feel free to remove it all.
void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot)
{
	using namespace System;
	using namespace UnityEngine;

	if (isFirstBoot)
	{
		String message("Game booted up");
		Debug::Log(message);

		GameObject go;
		String name("NativeScriptRoot");
		go.SetName(name);

		go.AddComponent<Native::BaseNativeScript>();
	}
}

#else

int main()
{
	Game::Get()->Init();

	constexpr float TICK_RATE = 1.0f / 64.0f;
	constexpr float ITERATIONS = 1;

	for (int i = 0; i < ITERATIONS; i++)
	{
		Game::Get()->Update(TICK_RATE);
	}

	return 0;
}

#endif