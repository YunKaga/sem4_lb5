#ifndef MUSICLIBRARYAPI_HPP
#define MUSICLIBRARYAPI_HPP

#ifdef _WIN32
    #ifdef MUSIC_LIBRARY_EXPORTS
        #define MUSIC_API __declspec(dllexport)
    #else
        #define MUSIC_API __declspec(dllimport)
    #endif
#else
    #define MUSIC_API
#endif

#endif
