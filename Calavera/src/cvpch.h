#ifndef CVPCH_H
#define CVPCH_H

#include "Calavera/Core/PlatformDetection.h"

#ifdef CV_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Calavera/Core/Base.h"

#include "Calavera/Core/Log.h"

#include "Calavera/Debug/Instrumentor.h"

#ifdef CV_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#endif // !CVPCH_H
