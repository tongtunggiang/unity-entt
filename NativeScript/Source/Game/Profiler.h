#pragma once

#if UNITY_NATIVE_DLL
#include "Bindings.h"
#endif

// A convenient macro for function name as it's not built in
#ifndef __FUNCTION_NAME__
#	ifdef WIN32   //WINDOWS
#		define __FUNCTION_NAME__   __FUNCTION__  
#	else          //*NIX
#		define __FUNCTION_NAME__   __func__ 
#	endif
#endif

// Profiler macros
#if !UNITY_NATIVE_DLL
#	define PROFILER_BEGIN(x) \
			std::string sectionName(x); \
			auto start = std::chrono::high_resolution_clock::now(); \

#	define PROFILER_END() \
			auto end = std::chrono::high_resolution_clock::now();										\
			auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);				\
			std::cout << "Execution time: " << sectionName << ": " << diff.count() << "ms" <<std::endl	\

#	define PROFILER_FUNCTION()	PROFILER_BEGIN(__FUNCTION_NAME__)

#else  // UNITY_NATIVE_DLL
#	if !FINAL_BUILD
#		define USE_PROFILER true
#	else
#		define USE_PROFILER false
#	endif

#	if USE_PROFILER
#		define PROFILER_BEGIN(x)	UnityEngine::Profiling::Profiler::BeginSample(System::String(x))
#		define PROFILER_END()		UnityEngine::Profiling::Profiler::EndSample()
#		define PROFILER_FUNCTION()	PROFILER_BEGIN(__FUNCTION_NAME__)
#	else // USE_PROFILER
#		define PROFILER_BEGIN(x)
#		define PROFILER_END()
#		define PROFILER_FUNCTION()
#	endif // USE_PROFILER
#endif // UNITY_NATIVE_DLL