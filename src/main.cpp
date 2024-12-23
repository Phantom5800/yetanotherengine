#include <iostream>
#include "framework/core/Platform.h"
#ifdef PLAT_WINDOWS
#include <windows.h>
#endif

int game_main(int argc, char** argv)
{
    std::cout << "fucking finally!" << std::endl;
    return 0;
}

#ifdef PLAT_WINDOWS
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return game_main(__argc, __argv);
}
#else
int main (int argc, char** argv)
{
    return game_main(argc, argv);
}
#endif
