#pragma once

#include "compiler_preprocessing.h"

#define global_variable static
#define internal static

#if defined(UNITY_BUILD)

#define API static

#elif defined(BUILD_STATIC_LIB)

#define API

#elif defined(BUILD_DLL)

#define API extern "C" DLL_EXPORT

#elif defined(USING_DLL)

#define API extern "C" DLL_IMPORT

#else

#define API 

#endif


#if defined(CALL_CONVENTION_STDCALL)

#define CALL_CONVENTION STDCALL_CONVENTION

#elif defined(CALL_CONVENTION_CDECL)

#define CALL_CONVENTION CDECL_CONVENTION

#else 

#define CALL_CONVENTION

#endif

struct v2
{
    float x;
    float y;
};

struct v3
{
    float x;
    float y;
    float z;
};


API void CALL_CONVENTION PrintOneTwoThree();
typedef void CALL_CONVENTION type_PrintOneTwoThree();

API void CALL_CONVENTION Print(v3 v);
typedef void CALL_CONVENTION type_PrintV3(v3 v);

API v3 CALL_CONVENTION Normalize(v3 v);
typedef v3 CALL_CONVENTION type_NormalizeV3(v3 v);

v3  CALL_CONVENTION operator+(v3 a, v3 b);
typedef v3 CALL_CONVENTION type_V3Add(v3 a, v3 b);

v3  CALL_CONVENTION operator+=(v3 &a, v3 b);
typedef void CALL_CONVENTION type_AddV3(v3 &a, v3 b);

global_variable v3 oneTwoThree = v3{1.0f, 2.0f, 3.0f};

/*
API void Print(v2 v);
typedef API void type_PrintV2(v2 v);

API v2 Normalize(v2 v);
typedef API v2 type_NormalizeV2(v2 v);

API v2  operator+(v2 a, v2 b);
typedef API v2 type_V2Add(v2 a, v2 b);

API v2  operator+=(v2 &a, v2 b);
typedef API v2 type_AddV2(v2 &a, v2 b);
*/