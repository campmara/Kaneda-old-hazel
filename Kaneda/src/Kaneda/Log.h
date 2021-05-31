#ifndef LOG_H
#define LOG_H

#include <memory.h>

#include "Core.h"

#include "spdlog/spdlog.h"

namespace Kaneda {
    class KANEDA_API Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#endif

// Core Log Macros
#define K_CORE_TRACE(...)    ::Kaneda::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define K_CORE_INFO(...)     ::Kaneda::Log::GetCoreLogger()->info(__VA_ARGS__)
#define K_CORE_WARN(...)     ::Kaneda::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define K_CORE_ERROR(...)    ::Kaneda::Log::GetCoreLogger()->error(__VA_ARGS__)
#define K_CORE_FATAL(...)    ::Kaneda::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define K_TRACE(...)         ::Kaneda::Log::GetClientLogger()->trace(__VA_ARGS__)
#define K_INFO(...)          ::Kaneda::Log::GetClientLogger()->info(__VA_ARGS__)
#define K_WARN(...)          ::Kaneda::Log::GetClientLogger()->warn(__VA_ARGS__)
#define K_ERROR(...)         ::Kaneda::Log::GetClientLogger()->error(__VA_ARGS__)
#define K_FATAL(...)         ::Kaneda::Log::GetClientLogger()->fatal(__VA_ARGS__)