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
    
    cerr << timeinfo->tm_year + 1900 << "-";
    
    if(timeinfo->tm_mon + 1 < 10)
        cerr << "0"; 
    cerr << timeinfo->tm_mon + 1 << "-";
    
    if(timeinfo->tm_mday < 10)
        cerr << "0";
    cerr << timeinfo->tm_mday << " ";
    
    if(timeinfo->tm_hour < 10)
        cerr << "0";
    cerr << timeinfo->tm_hour << ":";
    
    if(timeinfo->tm_min < 10)
        cerr << "0";
    cerr << timeinfo->tm_min << ":";
            
    if(timeinfo->tm_sec < 10)
        cerr << "0";
    cerr << timeinfo->tm_sec << " ";
}
