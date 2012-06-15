#include "Packet.h"

using namespace std;

Packet::Packet(char t) :
    m_type(t)
{
}

Packet::~Packet()
{
}

char Packet::type() const
{
    return m_type;
}

void Packet::saveInt(char *buffer, int number)
{
    char *bufNum = (char *)&number;
    
    for(int i = 0; i < 4; i++)
        buffer[i] = bufNum[i];
}

int Packet::readInt(const char *buffer)
{
    int result;
    
    char *bufRes = (char *)&result;
    
    for(int i = 0; i < 4; i++)
        bufRes[i] = buffer[i];
    
    return result;
}

void Packet::saveFloat(char *buffer, float number)
{
    char *bufNum = (char *)&number;
    
    for(int i = 0; i < 4; i++)
        buffer[i] = bufNum[i];
}

float Packet::readFloat(const char *buffer)
{
    float result;
    
    char *bufRes = (char *)&result;
    
    for(int i = 0; i < 4; i++)
        bufRes[i] = buffer[i];
    
    return result;
}

void Packet::saveString(char *buffer, const string &text)
{
    saveInt(buffer, text.length());
    
    char *buf = buffer + 4;
    
    for(int i = 0; i < (int)text.length(); i++)
        buf[i] = text.at(i);
}

string Packet::readString(const char *buffer)
{
    int length = readInt(buffer);
    const char *buf = buffer + 4;
    
    string result;
    
    for(int i = 0; i < length; i++)
        result.append(1, buf[i]);
    
    return result;
}
