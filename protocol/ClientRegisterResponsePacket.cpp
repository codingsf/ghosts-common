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

void ClientRegisterResponsePacket::read(const char *data, unsigned int /*len*/)
{
    m_hashedPassword = readString(data);
}

void ClientRegisterResponsePacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_hashedPassword);
}

int ClientRegisterResponsePacket::length() const
{
    return 4 + m_hashedPassword.length();
}
