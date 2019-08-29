//
// Created by Lorenzo on 8/28/2019.
//

#include "HelLogger.h"

int main() {
    //Initialize
    HelLogger::InitializeLogger();

    HelLogger::LogGame(LOGGING_LEVEL_DEBUG, "Logging game - Should display");
    HelLogger::LogCore(LOGGING_LEVEL_DEBUG, "Logging core - Should display");

    // Test level setting
    HelLogger::SetGameLoggerLevel(LOGGING_LEVEL_WARN);
    HelLogger::SetCoreLoggerLevel(LOGGING_LEVEL_INFO);

    // Bad log - Level changed
    auto badLog = HelLogger::LogPayload{LOGGING_LEVEL_TRACE, "SHOULD NOT DISPLAY"};

    HelLogger::LogGame(badLog);
    HelLogger::LogCore(badLog);

    // Change pattern
    HelLogger::SetGameLoggerPattern("[%n] [%D] %l : %v");
    HelLogger::SetCoreLoggerPattern("[%n] [%D] %l - %v");

    auto goodLog = HelLogger::LogPayload{LOGGING_LEVEL_CRITICAL, "SHOULD DISPLAY NEW PATTERN"};

    HelLogger::LogGame(goodLog);
    HelLogger::LogCore(goodLog);

    HelLogger::SetCoreLoggerPattern("[%n] [%D %T] [thread : %t] %l : %v");
    HelLogger::LogCore(LOGGING_LEVEL_CRITICAL, "Logging test complete");
}