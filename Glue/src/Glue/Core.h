#pragma once

#ifdef GLUE_PLATFORM_WINDOWS
	#ifdef GLUE_BUILD_DLL
		#define GLUE_API __declspec(dllexport)
	#else
		#define GLUE_API __declspec(dllimport)
	#endif
#else
	#error Glue currently supports Windows only!
#endif