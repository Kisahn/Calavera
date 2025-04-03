#pragma once

#ifdef CV_PLATFORM_WINDOWS
	#ifdef CV_BUILD_DLL
		#define CALAVERA_API __declspec(dllexport)
	#else
		#define CALAVERA_API __declspec(dllimport)
	#endif // CV_BUILD_DLL
#else
	#error Calavera only supports Windows !
#endif