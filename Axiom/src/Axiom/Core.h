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

#define BIT(x) (1 << x)