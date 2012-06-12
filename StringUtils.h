#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>

class StringUtils
{
public:
    static std::string bytesToString(const unsigned char *data, int length);
    static unsigned char *stringToBytes(const std::string &data);
    
private:
    static char halfByte(unsigned char h);
    static unsigned char halfByte(char c);
    
};

#endif // STRINGUTILS_H
