#ifndef CORE_H
#define CORE_H

	#ifdef CV_PLATFORM_WINDOWS
		#ifdef CV_BUILD_DLL
			#define CALAVERA_API __declspec(dllexport)
		#else
			#define CALAVERA_API __declspec(dllimport)
		#endif
	#else
		#error Calavera only supports Windows !
	#endif

	#ifdef CV_ENABLE_ASSERTS
		#define CV_ASSERT(x, ...) { if(!(x)) { CV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define CV_CORE_ASSERT(x, ...) { if(!(x)) { CV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define CV_ASSERT(x, ...)
		#define CV_CORE_ASSERT(x, ...)
	#endif // CV_ENABLE_ASSERTS

	#define BIT(x) (1 << x)

#endif // !CORE_H