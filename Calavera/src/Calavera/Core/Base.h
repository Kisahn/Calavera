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

#define CV_EXPAND_MACRO(x) x
#define CV_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define CV_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

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

#include "Calavera/Core/Log.h"
#include "Calavera/Core/Assert.h"

#endif // !BASE_H