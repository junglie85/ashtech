#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#if defined(_MSC_VER)
#define AT_DLL_EXPORT __declspec(dllexport)
#else
#define AT_DLL_EXPORT __attribute__((visibility("default")))
#endif

#define AT_EXPAND(value) value
#define AT_STRINGIFY_IMPL(str) #str
#define AT_STRINGIFY(str) AT_STRINGIFY_IMPL(str)
