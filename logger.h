//
// Created by Lorenzo on 8/26/2019.
//

#ifndef HEL_LOGGING_LOGGER_H
#define HEL_LOGGING_LOGGER_H

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "HelLogger.h"

// Spdlog implementation header

namespace SpdLogger {
    class Logger {
    public :
        static void InitializeLogger();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return _gameLogger; }

        inline static void SetCoreLoggerPattern(const char* pattern) {Logger::_coreLogger->set_pattern(pattern);}
        inline static void SetGameLoggerPattern(const char* pattern) {Logger::_gameLogger->set_pattern(pattern);}

        inline static void SetCoreLoggerLevel(spdlog::level::level_enum level) {Logger::_coreLogger->set_level(level);}
        inline static void SetGameLoggerLevel(spdlog::level::level_enum level) {Logger::_gameLogger->set_level(level);}

        static spdlog::level::level_enum MapLoggingLevelToSpdlogLevel(HelLogger::Level::LoggingLevel level);

        inline static void LogToLevel(std::shared_ptr<spdlog::logger>& logger, spdlog::level::level_enum level, const char* msg) { logger->log(level, msg); }

    private :
        static std::shared_ptr<spdlog::logger> _coreLogger;
        static std::shared_ptr<spdlog::logger> _gameLogger;
    };
}

// Example log: [Core] [08/23/19 17:32:05] [thread : 3] debug : My awesome message!
// [Core (%n)] [08/23/19 (%D) 17:32:05 (%T)] [thread : 3 %t] debug (%l) : My awesome message! (%v)
#define SPDLOG_DEFAULT_PATTERN "[%n] [%D %T] [thread : %t] %l : %v"

#endif //HEL_LOGGING_LOGGER_H
