//
// Created by Lorenzo on 8/26/2019.
//

#include "logger.h"

namespace SpdLogger {
    std::shared_ptr<spdlog::logger> Logger::_coreLogger;
    std::shared_ptr<spdlog::logger> Logger::_gameLogger;

    void Logger::InitializeLogger() {
        spdlog::set_pattern(SPDLOG_DEFAULT_PATTERN);

        Logger::_coreLogger = spdlog::stdout_color_mt("Core");
        Logger::_gameLogger = spdlog::stdout_color_mt("Game");

        Logger::_coreLogger->set_level(spdlog::level::level_enum::trace);
        Logger::_gameLogger->set_level(spdlog::level::level_enum::debug);
    }

    spdlog::level::level_enum Logger::MapLoggingLevelToSpdlogLevel(HelLogger::Level::LoggingLevel level) {
        switch(level) {
            case LOGGING_LEVEL_TRACE :      return spdlog::level::level_enum::trace;
            case LOGGING_LEVEL_INFO :       return spdlog::level::level_enum::info;
            case LOGGING_LEVEL_DEBUG :      return spdlog::level::level_enum::debug;
            case LOGGING_LEVEL_WARN :       return spdlog::level::level_enum::warn;
            case LOGGING_LEVEL_ERR :        return spdlog::level::level_enum::err;
            case LOGGING_LEVEL_CRITICAL :   return spdlog::level::level_enum::critical;
            default : return spdlog::level::level_enum::off;
        }
    }
}