#include <string>
#ifndef CONSOLE_H
#define CONSOLE_H

using std::string;

enum class LogLevel
{
    INFO,
    WARN,
    ERROR
};

void log(LogLevel level, string tag, string msg);

#endif