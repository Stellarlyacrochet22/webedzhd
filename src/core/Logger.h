#pragma once

#include <string>

namespace hwid {

enum class LogLevel { Info, Warn, Error };

class Logger {
public:
    static void init();
    static void log(LogLevel level, const std::string& message);
};

} // namespace hwid
