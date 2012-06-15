#include "Environment.h"

#include <fstream>
#include <sstream>

#include "Logger.h"

using namespace std;

Environment *Environment::m_instance = 0;

Environment::Environment()
{
}

bool Environment::load(const std::string &filename)
{
    clear();
    
    ifstream file(filename.c_str());
    
    if(!file.is_open())
    {
        Logger::error("Unable to open file: " + filename);
        return false;
    }
    
    while(!file.eof())
    {
        string line;
        getline(file, line);
        
        if(line.length() == 0 || line.at(0) == '#')
            continue;
        
        size_t delimiterPosition = line.rfind("=");
        
        if(delimiterPosition == string::npos)
            continue;
        
        string key = line.substr(0, delimiterPosition),
               value = line.substr(delimiterPosition + 1);
        
        Logger::debug(key + " " + value);
        
        m_values[key] = value;
    }
    
    file.close();
    return true;
}

bool Environment::save(const string &filename) const
{
    ofstream file(filename.c_str());
    
    if(!file.is_open())
    {
        Logger::error("Unable to open file: " + filename);
        return false;
    }
    
    for(map<string, string>::const_iterator it = m_values.begin(); it != m_values.end(); it++)
        file << it->first << "=" << it->second << endl;
    
    file.close();
    return true;
}

std::string Environment::value(const std::string &key) const
{
    if(m_values.count(key) > 0)
        return m_values.at(key);
    
    return "";
}

void Environment::setValue(const std::string &key, const std::string &value)
{
    m_values[key] = value;
}

void Environment::clear()
{
    m_values.clear();
}

bool Environment::init(const std::string &filename)
{
    Environment *inst = instance();
    
    return inst->load(filename);
}

Environment *Environment::instance()
{
    if(m_instance == 0)
        m_instance = new Environment();
    
    return m_instance;
}

void Environment::clean()
{
    if(m_instance != 0)
    {
        delete m_instance;
        m_instance = 0;
    }
}

int Environment::toInt(const string &value)
{
    int buffer;
    
    stringstream ss;
    ss << value;
    ss >> buffer;
    
    return buffer;
}

float Environment::toFloat(const string &value)
{
    float buffer;
    
    stringstream ss;
    ss << value;
    ss >> buffer;
    
    return buffer;
}
