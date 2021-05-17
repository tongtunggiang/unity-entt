#pragma once

#if UNITY_NATIVE_DLL

#include "World.h"

namespace Native
{
struct NativeScript : Native::BaseNativeScript
{
	NATIVE_NATIVE_SCRIPT_DEFAULT_CONTENTS
	NATIVE_NATIVE_SCRIPT_DEFAULT_CONSTRUCTOR

public:
	void PassGameConfig(void* config) override;
	void StartSimulation() override;
	void Update() override;

};
}

#endif
