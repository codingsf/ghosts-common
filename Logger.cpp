#include "Logger.h"

#include <ctime>
#include <iostream>

using namespace std;

Logger::LogLevel Logger::m_logLevel = Logger::Info;

void Logger::setLogLevel(Logger::LogLevel level)
{
    m_logLevel = level;
}

Logger::LogLevel Logger::logLevel()
{
    return m_logLevel;
}

void Logger::error(const std::string &message)
{
    printLocalTime();
    
    cerr << "[ERROR] " << message << endl; 
}

void Logger::warning(const string &message)
{
    if(m_logLevel >= Warning)
    {
        printLocalTime();
        cerr << "[WARNING] " << message << endl;
    }
}

void Logger::info(const string &message)
{
    if(m_logLevel >= Info)
    {
        printLocalTime();
        cerr << "[INFO] " << message << endl;
    }
}

void Logger::debug(const string &message)
{
    if(m_logLevel >= Debug)
    {
        printLocalTime();
        cerr << "[DEBUG] " << message << endl;
    }
}



void Logger::printLocalTime()
{
    time_t currentTime;
    tm *timeinfo;
    
    time(&currentTime);
    timeinfo = localtime(&currentTime);
    
    cerr << asctime(timeinfo) << " ";
}
