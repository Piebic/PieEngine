#pragma once

#ifdef WIN_API

	#ifdef BUILD_DLL
		#define PIE_API __declspec(dllexport)
	#else
		#define PIE_API __declspec(dllimport)
	#endif // BUILD_DLL

#else

	#error Platform not supported

#endif // WIN_API