#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include<cstdlib>
#include<limits>
#include<ctime>

#define FLUSH_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
#define RESET_CIN std::cin.clear(); FLUSH_BUFFER

inline int randBetween(int min, int max) {return (rand() % ((max + 1) - min)) + (min);};

// For cross-platform functionality.
#if defined(_WIN32) || defined(WIN32)
    #include <windows.h> // for Sleep
    #define CLEAR_WINDOW system("CLS")
    #define SLEEP(x) Sleep(x)
#elif defined(__unix__)
    #include <unistd.h> // for usleep
    #define CLEAR_WINDOW system("clear")
    #define SLEEP(x) usleep(x * 1000)
#endif


#endif