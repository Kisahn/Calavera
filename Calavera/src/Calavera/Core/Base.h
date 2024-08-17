#ifndef CORE_H
#define CORE_H

#include <memory>

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64 */
		#define CV_PLATFORM_WINDOWS
	#else
		/* Windows x86 */
		#error "x86 Builds are not supported!"
	#endif
	#elif defined (__APPLE__) || defined(__MACH__)
		#include <TargetConditionals.h>
		/*  TARGET_OS_MAC exists on all the platforms
		 *  so we must check all of them (in this order)
		 *  to ensure that we're running on MAX
		 *  and not some other Apple platform */
		#if TARGET_IPHONE_SIMULATOR == 1
			#error "IOS simulator is not supported!"
		#elif TARGET_OS_IPHONE == 1
			#define CV_PLATFORM_IOS
			#error "IOS is not supported!"
		#elif TARGET_OS_MAC == 1
			#define CV_PLATFORM_MACOS
			#define "MacOS is not supported!"
		#else
			#error "Unknown Apple platform!"
		#endif
		/* We also have to check __ANDROID__ before __linux__
		* since android is based on the linux kernel
		* it has __linux__ defined */
		#elif defined (__ANDROID__)
			#define CV_PLATFORM_ANDROID
			#error "Android is not supported!"
		#elif defined (__linux__)
			#define CV_PLATFORM_LINUX
			#error "Linux is not supported!"
		#else
			/* Unknow compiler/platform */
			#error "Unknown platform!"
#endif // End of platform detection

// DLL support
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
#endif // End of DLL support

#ifdef CV_DEBUG
	#define CV_ENABLE_ASSERTS
#endif

#ifdef CV_ENABLE_ASSERTS
	#define CV_ASSERT(x, ...) { if(!(x)) { CV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CV_CORE_ASSERT(x, ...) { if(!(x)) { CV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
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
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

}

#endif // !CORE_H