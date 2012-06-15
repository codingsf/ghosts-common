#include "ServerRegisterChallengePacket.h"

ServerRegisterChallengePacket::ServerRegisterChallengePacket(const std::string &publicKey, 
                                                             const std::string &salt) :
    Packet(Type), m_publicKey(publicKey), m_salt(salt)
{
}

std::string ServerRegisterChallengePacket::publicKey() const
{
    return m_publicKey;
}

std::string ServerRegisterChallengePacket::salt() const
{
    return m_salt;
}

void ServerRegisterChallengePacket::setPublicKey(const std::string &publicKey)
{
    m_publicKey = publicKey;
}

void ServerRegisterChallengePacket::setSalt(const std::string &salt)
{
    m_salt = salt;
}

void ServerRegisterChallengePacket::read(const char *data, unsigned int /*len*/)
{
    m_publicKey = readString(data);
    m_salt = readString(data + (4 + m_publicKey.length()));
}

void ServerRegisterChallengePacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_publicKey);
    saveString(buffer + 4 + m_publicKey.length(), m_salt);
}

int ServerRegisterChallengePacket::length() const
{
    return 8 + m_publicKey.length() + m_salt.length();
}
