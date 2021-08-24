#include <iostream>
#include <windows.h>
#include <libloaderapi.h>

typedef void (__cdecl* function_type)();

int main()
{
    while (1)
    {
        std::cout << "Enter to continue...";
        getchar();

        function_type function;
        HINSTANCE dll_handler;

        dll_handler = LoadLibraryA("power.dll");
        if (dll_handler == NULL)
        {
            std::cout << "Error: Unable to load dll" << std::endl;
            continue;
        }

        if ((function = (function_type)GetProcAddress(dll_handler, "function")) == NULL)
        {
            std::cout << "Error: Unable to find function 'initialize' entry point in dll" << std::endl;
        }
        else
        {
            function();
            std::cout << "function() returned " << std::endl;
        }

        //std::cout << "FreeLibraryAndExitThread() before" << std::endl;
        //FreeLibraryAndExitThread(dll_handler, 0);
        std::cout << "Enter to FreeLibrary()...";
        getchar();
        int res = FreeLibrary(dll_handler);
        if (res == 0)
        {
            std::cout << "FreeLibrary() failed" << std::endl;
        }
        else
        {
            std::cout << "FreeLibrary() succeed" << std::endl;
        }
        //std::cout << "FreeLibraryAndExitThread() after" << std::endl;
    }

    return 0;
}

