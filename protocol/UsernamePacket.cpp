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

void UsernamePacket::read(const char *data, unsigned int /*len*/)
{
    m_username = readString(data);
}

void UsernamePacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_username);
}

int UsernamePacket::length() const
{
    return 4 + m_username.length();
}
