#include "Logger.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>

namespace hwid {

static std::ofstream g_log;

void Logger::init() {
    char temp[MAX_PATH]{};
    if (GetTempPathA(MAX_PATH, temp)) {
        g_log.open(std::string(temp) + "hwid-spoofer.log", std::ios::app);
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    const char* tag = level == LogLevel::Info ? "INFO" :
                      level == LogLevel::Warn ? "WARN" : "ERROR";
    std::string line = std::string("[") + tag + "] " + message;
    std::cout << line << '\n';
    if (g_log.is_open()) g_log << line << '\n';
}

} // namespace hwid
