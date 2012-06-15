#include "UsernamePacket.h"

#include "../Logger.h"

UsernamePacket::UsernamePacket(char type) :
    Packet(type), m_username("")
{
    if(type != Register && type != Login)
        Logger::error("UsernamePacket: Invalid packet type");
}

std::string UsernamePacket::username() const
{
    return m_username;
}

void UsernamePacket::setUsername(const std::string &username)
{
    m_username = username;
}

char *UsernamePacket::serialize(int &len) const
{
    len = 9 + m_username.length();
    
    char *result = new char[len];
    char *buffer = result;
    
    saveInt(buffer, len);
    
    buffer += 4;
    
    buffer[0] = m_type;
    saveString(buffer + 1, m_username);
    
    return result;
}

void UsernamePacket::read(const char *data, unsigned int /*len*/)
{
    m_username = readString(data);
}
