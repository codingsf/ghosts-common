#include "ErrorPacket.h"

ErrorPacket::ErrorPacket() :
    Packet(Type), m_message("No error - WTF?")
{
}

ErrorPacket::ErrorPacket(const std::string &message) :
    Packet(Type), m_message(message)
{
}

void ErrorPacket::setMessage(const std::string &message)
{
    m_message = message;
}

std::string ErrorPacket::message() const
{
    return m_message;
}

char *ErrorPacket::serialize(int &len) const
{
    len = 9 + m_message.length();
    
    char *result = new char[len];
    
    char *buffer = result;
    
    saveInt(buffer, len);
    buffer += 4;
    
    buffer[0] = Type;
    
    saveString(buffer + 1, m_message);
    
    return result;
}

void ErrorPacket::read(const char *data, unsigned int /*len*/)
{
    m_message = readString(data);
}
