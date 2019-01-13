#pragma once

#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#if defined(_MSC_VER)
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#define STDCALL_CONVENTION __stdcall
#define CDECL_CONVENTION __cdecl
#elif defined(__GNUC__)
#define DLL_EXPORT __attribute__((visibility("default")))
#define DLL_IMPORT
#if defined(ENVIRONMENT32)
#define STDCALL_CONVENTION __attribute__((stdcall))
#define CDECL_CONVENTION   __attribute__((cdecl))
#else
#define STDCALL_CONVENTION
#define CDECL_CONVENTION
#endif
#endif


