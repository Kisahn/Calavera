#ifndef CORE_H
#define CORE_H

#include <memory>

#ifdef CV_PLATFORM_WINDOWS
	#if CV_DYNAMIC_LINK
		#ifdef CV_BUILD_DLL
			#define CALAVERA_API __declspec(dllexport)
		#else
			#define CALAVERA_API __declspec(dllimport)
		#endif
	#else
		#define CALAVERA_API
	#endif
#else
	#error Calavera only supports Windows !
#endif

#ifdef CV_DEBUG
	#define CV_ENABLE_ASSERTS
#endif // CV_DEBUG


#ifdef CV_ENABLE_ASSERTS
	#define CV_ASSERT(x, ...) { if(!(x)) { CV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CV_CORE_ASSERT(x, ...) { if(!(x)) { CV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CV_ASSERT(x, ...)
	#define CV_CORE_ASSERT(x, ...)
#endif // CV_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define CV_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Calavera {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}

#endif // !CORE_H