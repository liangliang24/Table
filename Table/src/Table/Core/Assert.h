#pragma once

#pragma once

#include "Table/Core/Core.h"
#include "Table/Core/Log.h"
#include <filesystem>

#ifdef TABLE_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define TABLE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { TABLE##type##ERROR(msg, __VA_ARGS__); TABLE_DEBUGBREAK(); } }
#define TABLE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) TABLE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define TABLE_INTERNAL_ASSERT_NO_MSG(type, check) TABLE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TABLE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define TABLE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define TABLE_INTERNAL_ASSERT_GET_MACRO(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, TABLE_INTERNAL_ASSERT_WITH_MSG, TABLE_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define TABLE_ASSERT(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define TABLE_CORE_ASSERT(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define TABLE_ASSERT(...)
#define TABLE_CORE_ASSERT(...)
#endif

#ifdef TABLE_ENABLE_VERIFY

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define TABLE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { TABLE##type##ERROR(msg, __VA_ARGS__); TABLE_DEBUGBREAK(); } }
#define TABLE_INTERNAL_VERIFY_WITH_MSG(type, check, ...) TABLE_INTERNAL_VERIFY_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define TABLE_INTERNAL_VERIFY_NO_MSG(type, check) TABLE_INTERNAL_VERIFY_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TABLE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define TABLE_INTERNAL_VERIFY_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define TABLE_INTERNAL_VERIFY_GET_MACRO(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_VERIFY_GET_MACRO_NAME(__VA_ARGS__, TABLE_INTERNAL_VERIFY_WITH_MSG, TABLE_INTERNAL_VERIFY_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define TABLE_VERIFY(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_VERIFY_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define TABLE_CORE_VERIFY(...) TABLE_EXPAND_MACRO( TABLE_INTERNAL_VERIFY_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define TABLE_VERIFY(...)
#define TABLE_CORE_VERIFY(...)
#endif