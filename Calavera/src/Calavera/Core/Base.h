#ifndef BASE_H
#define BASE_H

#include <memory>

#include "Calavera/Core/PlatformDetection.h"

#ifdef CV_DEBUG
	#if defined(CV_PLATFORM_WINDOWS)
		#define CV_DEBUGBREAK() __debugbreak()
	#elif defined(CV_PLATFORM_LINUX)
		#include <signal.h>
		#define CV_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define CV_ENABLE_ASSERTS
#else
	#define CV_DEBUGBREAK()
#endif

// TODO: Make this macro able to take in no arguments except condition
#ifdef CV_ENABLE_ASSERTS
	#define CV_ASSERT(x, ...) { if(!(x)) { CV_ERROR("Assertion Failed: {0}", __VA_ARGS__); CV_DEBUGBREAK(); } }
	#define CV_CORE_ASSERT(x, ...) { if(!(x)) { CV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); CV_DEBUGBREAK(); } }
#else
	#define CV_ASSERT(x, ...)
	#define CV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CV_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Calavera {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#endif // !BASE_H