#pragma once

#ifdef GLUE_PLATFORM_WINDOWS
#if GLUE_DYNAMIC_LINK
	#ifdef GLUE_BUILD_DLL
		#define  __declspec(dllexport)
	#else
		#define __declspec(dllimport)
	#endif
#else
	#define GLUE_API
#endif
#else
	#error Glue currently supports Windows only!
#endif

#ifdef GLUE_ENABLE_ASSERTS
	#define GLUE_ASSERT(x, ...) { if(!(x)) { GLUE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GLUE_CORE_ASSERT(x, ...) { if(!(x)) { GLUE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GLUE_ASSERT(x, ...)
	#define GLUE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GLUE_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

typedef unsigned int uint;
typedef unsigned char byte;