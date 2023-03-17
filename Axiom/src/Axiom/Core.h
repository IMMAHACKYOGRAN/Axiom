#pragma once

#ifdef AX_PLATFORM_WINDOWS
	#ifdef AX_BUILD_DLL
		#define AXIOM_API __declspec(dllexport)
	#else
		#define AXIOM_API __declspec(dllimport)
	#endif
#else
	#error Axiom only supports Windows
#endif


#ifdef AX_ENABLE_ASSERTS
	#define AX_ASSERT(x, ...) { if(!(x)) { AX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AX_CORE_ASSERT(x, ...) { if(!(x)) { AX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AX_ASSERT(x, ...)
	#define AX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)