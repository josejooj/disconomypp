#include <iostream>
#include <string>
#include "log.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

void log(LogLevel level, string tag, string msg)
{
    switch (level)
    {

    case LogLevel::INFO:
        cout << "\x1b[32m[\x1b[36m\x1b[4mINFO - " + tag + "\x1b[0m\x1b[32m]\x1b[0m - " << msg << endl;
        break;

    case LogLevel::WARN:
        cout << "\x1b[32m[\x1b[32m\x1b[4mWARN - " + tag + "\x1b[0m\x1b[32m]\x1b[0m - " << msg << endl;
        break;

    case LogLevel::ERROR:
        cout << "\x1b[32m[\x1b[31m\x1b[4mERROR - " + tag + "\x1b[0m\x1b[32m]\x1b[0m - " << msg << endl;
        break;

    default:
        cout << "[" << tag << "] - " << msg << endl;
        break;
    }
}