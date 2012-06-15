#include "ClientRegisterResponsePacket.h"

ClientRegisterResponsePacket::ClientRegisterResponsePacket(const std::string &hashedPassword) :
    Packet(Type), m_hashedPassword(hashedPassword)
{
}

std::string ClientRegisterResponsePacket::hashedPassword() const
{
    return m_hashedPassword;
}

void ClientRegisterResponsePacket::setHashedPassword(const std::string &hashedPassword)
{
    m_hashedPassword = hashedPassword;
}

char *ClientRegisterResponsePacket::serialize(int &len) const
{
    len = 9 + m_hashedPassword.length();
    
    char *result = new char[len];
    char *buffer = result;
    
    saveInt(buffer, len);
    buffer += 4;
    
    buffer[0] = Type;
    buffer += 1;
    
    saveString(buffer, m_hashedPassword);
    
    return result;
}

void ClientRegisterResponsePacket::read(const char *data, unsigned int /*len*/)
{
    m_hashedPassword = readString(data);
}
