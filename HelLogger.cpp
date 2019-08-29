//
// Created by Lorenzo on 8/8/2019.
//

#include "HelLogger.h"
#include "logger.h"

void HelLogger::InitializeLogger() {
    SpdLogger::Logger::InitializeLogger();
}

void HelLogger::SetCoreLoggerLevel(Level::LoggingLevel level) {
    auto spdlogLevel = SpdLogger::Logger::MapLoggingLevelToSpdlogLevel(level);
    SpdLogger::Logger::SetCoreLoggerLevel(spdlogLevel);
}

void HelLogger::SetGameLoggerLevel(Level::LoggingLevel level) {
    auto spdlogLevel = SpdLogger::Logger::MapLoggingLevelToSpdlogLevel(level);
    SpdLogger::Logger::SetGameLoggerLevel(spdlogLevel);
}

void HelLogger::SetCoreLoggerPattern(char *pattern) {
    SpdLogger::Logger::SetCoreLoggerPattern(pattern);
}

void HelLogger::SetGameLoggerPattern(char *pattern) {
    SpdLogger::Logger::SetGameLoggerPattern(pattern);
}


void HelLogger::LogGame(HelLogger::Level::LoggingLevel LogLevel, const char* message) {
     SpdLogger::Logger::LogToLevel(
            SpdLogger::Logger::GetGameLogger(),
            SpdLogger::Logger::MapLoggingLevelToSpdlogLevel(LogLevel),
            message);
}

void HelLogger::LogCore(HelLogger::Level::LoggingLevel LogLevel, const char* message) {
    SpdLogger::Logger::LogToLevel(
            SpdLogger::Logger::GetCoreLogger(),
            SpdLogger::Logger::MapLoggingLevelToSpdlogLevel(LogLevel),
            message);
}


