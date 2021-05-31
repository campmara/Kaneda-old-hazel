#ifndef CORE_H
#define CORE_H

#ifdef K_PLATFORM_WINDOWS
#ifdef K_BUILD_DLL
#define KANEDA_API __declspec(dllexport)
#else
#define KANEDA_API __declspec(dllimport)
#endif
#else
#error Kaneda only supports Windows!
#endif

#define BIT(x) (1 << x)

#endif