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

#endif // !CORE_H
