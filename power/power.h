#pragma once

#if defined __cplusplus
extern "C"
{
#endif

#if defined BUILDING_POWER_DL
    #define POWER_DL_DECL_SPEC __declspec(dllexport)
#else
    #define POWER_DL_DECL_SPEC __declspec(dllimport)
#endif

//extern int POWER_DL_DECL_SPEC __cdecl power(int base, int exp);
extern void POWER_DL_DECL_SPEC __cdecl function();

#if defined __cplusplus
}
#endif

