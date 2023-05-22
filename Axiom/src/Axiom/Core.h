#pragma once

#include <memory>

#ifdef AX_DEBUG
	#define AX_ENABLE_ASSERTS
#endif

#ifdef AX_ENABLE_ASSERTS
	#define AX_ASSERT(x, ...) { if(!(x)) { AX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AX_CORE_ASSERT(x, ...) { if(!(x)) { AX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AX_ASSERT(x, ...)
	#define AX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Axiom
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}