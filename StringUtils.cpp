#include "StringUtils.h"

using namespace std;

string StringUtils::bytesToString(const unsigned char *data, int length)
{
    string result = "";
    
    for(int i = 0; i < length; i++)
    {
        unsigned char c = data[i];
        
        result.append(1, halfByte((unsigned char)((c & 0xF0) >> 4)));
        result.append(1, halfByte((unsigned char)(c & 0x0F)));
    }
    
    return result;
}

unsigned char *StringUtils::stringToBytes(const string &data)
{
    int length = data.length()/2;
    int position = 0;
    
    unsigned char *result = new unsigned char[length];
    
    for(int i = 0; i < length; i++, position += 2)
    {
        result[i] = 0;
        result[i] |= halfByte(data.at(position)) << 4;
        result[i] |= halfByte(data.at(position + 1));
    }
    
    return result;
}

char StringUtils::halfByte(unsigned char h)
{    
    if(h <= 9)
        return '0' + h;
    
    if(h >= 10 && h <= 15)
        return 'A' + (h - 10);
    
    return '0';
}

unsigned char StringUtils::halfByte(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    
    if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    
    return 0;
}

