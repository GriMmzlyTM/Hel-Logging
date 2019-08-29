//
// Created by Lorenzo on 8/8/2019.
//

#ifndef HEL_LOGGING_HELLOGGER_H
#define HEL_LOGGING_HELLOGGER_H
// DO NOT MODIFY DEFINES, USED BY CORE

#define LOGGING_LEVEL_TRACE HelLogger::Level::LoggingLevel::TRACE
#define LOGGING_LEVEL_DEBUG HelLogger::Level::LoggingLevel::DEBUG
#define LOGGING_LEVEL_INFO HelLogger::Level::LoggingLevel::INFO
#define LOGGING_LEVEL_WARN HelLogger::Level::LoggingLevel::WARN
#define LOGGING_LEVEL_ERR HelLogger::Level::LoggingLevel::ERR
#define LOGGING_LEVEL_CRITICAL HelLogger::Level::LoggingLevel::CRITICAL

// DO NOT MODIFY CLASS -- USED BY CORE
class HelLogger {
public :
    class Level {
    public:
        typedef enum {
            TRACE,
            DEBUG,
            INFO,
            WARN,
            ERR,
            CRITICAL,
        } LoggingLevel;
    };

    struct LogPayload {
        Level::LoggingLevel LogLevel;
        const char* Message;
    };

    static void InitializeLogger();

    static void SetCoreLoggerLevel(Level::LoggingLevel level);
    static void SetGameLoggerLevel(Level::LoggingLevel level);

    static void SetCoreLoggerPattern(char* pattern);
    static void SetGameLoggerPattern(char* pattern);

    inline static void LogGame(const LogPayload& log) { LogGame(log.LogLevel, log.Message); }
    static void LogGame(Level::LoggingLevel LogLevel, const char* message);

    inline static void LogCore(const LogPayload& log) { LogCore(log.LogLevel, log.Message); }
    static void LogCore(Level::LoggingLevel LogLevel, const char* message);
};

// MODIFY to match default pattern for implemented logger
#define LOGGER_DEFAULT_PATTERN HelLogger::Logger::SPDLOG_DEFAULT_PATTERN

#endif //HEL_LOGGING_HELLOGGER_H
