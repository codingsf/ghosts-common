#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "ghosts-common_global.h"

#include <map>
#include <string>

class GHOSTSCOMMONSHARED_EXPORT Environment
{
public:
    static int toInt(const std::string &value);
    static float toFloat(const std::string &value);
    
    static bool init(const std::string &filename);
    static Environment *instance();
    static void clean();
    
    bool load(const std::string &filename);
    bool save(const std::string &filename) const;
    
    std::string value(const std::string &key) const;
    void setValue(const std::string &key, const std::string &value);
    
    void clear();
    
private:
    static Environment *m_instance;
    
    std::map<std::string, std::string> m_values;
    
    Environment();
    
};

#endif // ENVIRONMENT_H
