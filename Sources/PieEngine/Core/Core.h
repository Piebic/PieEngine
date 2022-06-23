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

#ifdef PIE_ASSERTS_ENABLED
	#define pieAssert(x, ...) { if(!(x)) { logError("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define pieCoreAssert(x, ...) { if(!(x)) { logPieError("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define pieAssert(x, ...) 
	#define pieCoreAssert(x, ...) 
#endif // ACR_BUILD_DLL

#define BIT(x) (1 << x)