#if defined(PLATFORM_WINDOWS)
#include <windows.h>
#elif defined(PLATFORM_LINUX)
#include <dlfcn.h>
#endif 

#include "vectors.h"
#include <stdio.h>

#if defined(UNITY_BUILD)
#include "vectors.cpp"
#endif


int main()
{
#if defined(USING_DLL)
#if defined(PLATFORM_WINDOWS)
    HMODULE dll = LoadLibraryA("vectors.dll");
    
    //type_PrintV2 *PrintV2 = (type_PrintV2*)GetProcAddress(dll, "PrintV2");
    //type_NormalizeV2 *NormalizeV2 = (type_NormalizeV2*)GetProcAddress(dll, "NormalizeV2");
    type_PrintOneTwoThree *PrintOneTwoThree = (type_PrintOneTwoThree*)GetProcAddress(dll, "PrintOneTwoThree");
    type_PrintV3 *Print = (type_PrintV3*)GetProcAddress(dll, "Print");
    type_NormalizeV3 *Normalize = (type_NormalizeV3*)GetProcAddress(dll, "Normalize");
#elif defined(PLATFORM_LINUX)
    void* dll = dlopen("./libvectors.so", RTLD_LAZY);
    fprintf(stderr, "%s\n", dlerror());
    type_PrintOneTwoThree *PrintOneTwoThree = (type_PrintOneTwoThree*)dlsym(dll,  "PrintOneTwoThree");
    type_PrintV3 *Print = (type_PrintV3*)dlsym(dll,  "Print");
    type_NormalizeV3 *Normalize = (type_NormalizeV3*)dlsym(dll,  "Normalize");
#endif
    fprintf(stdout, "DLL Handle: %p\nPrintOneTwoThree:%p\nPrintV3:%p\nNormalizeV3:%p\n", dll, PrintOneTwoThree, Print, Normalize);
#endif
    
    v3 a = {1, 0, 0};
    Print(a);
    v3 b = {0, 1, 1};
    Print(b);
    v3 c = a;
    Print(c);
    
    v3 d = Normalize(v3{c.x, c.y, 0.0f});
    Print(d);
    d.y = 100.0f;
    Print(d);
    
    v3 e = Normalize(d);
    Print(e);
    PrintOneTwoThree();
    
    return 0;
}

