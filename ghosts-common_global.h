#ifndef GHOSTSCOMMON_GLOBAL_H
#define GHOSTSCOMMON_GLOBAL_H

#if _WIN32
    #define DECL_EXPORT __declspec(dllexport)
    #define DECL_IMPORT __declspec(dllimport)
#else
    #define DECL_EXPORT
    #define DECL_IMPORT
#endif

#if defined(GHOSTSCOMMON_LIBRARY)
#  define GHOSTSCOMMONSHARED_EXPORT DECL_EXPORT
#else
#  define GHOSTSCOMMONSHARED_EXPORT DECL_IMPORT
#endif

#endif // GHOSTSCOMMON_GLOBAL_H
