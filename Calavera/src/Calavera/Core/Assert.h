#ifndef ASSERT_H
#define ASSERT_H

#include "Calavera/Core/Base.h"
#include "Calavera/Core/Log.h"
#include <filesystem>

#ifdef CV_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define CV_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CV##type##ERROR(msg, __VA_ARGS__); CV_DEBUGBREAK(); } }
	#define CV_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CV_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define CV_INTERNAL_ASSERT_NO_MSG(type, check) CV_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CV_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CV_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CV_INTERNAL_ASSERT_GET_MACRO(...) CV_EXPAND_MACRO( CV_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CV_INTERNAL_ASSERT_WITH_MSG, CV_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define CV_ASSERT(...) CV_EXPAND_MACRO( CV_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define CV_CORE_ASSERT(...) CV_EXPAND_MACRO( CV_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define CV_ASSERT(...)
	#define CV_CORE_ASSERT(...)
#endif

#endif // !ASSERT_H
