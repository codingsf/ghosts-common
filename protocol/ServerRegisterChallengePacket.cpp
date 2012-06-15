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

char *ServerRegisterChallengePacket::serialize(int &len) const
{
    len = 13 + m_publicKey.length() + m_salt.length();
    
    char *result = new char[len];
    char *buffer = result;
    
    saveInt(buffer, len);
    buffer += 4;
    
    buffer[0] = Type;
    buffer += 1;
    
    saveString(buffer, m_publicKey);
    buffer += 4 + m_publicKey.length();
    
    saveString(buffer, m_salt);
    
    return result;
}

void ServerRegisterChallengePacket::read(const char *data, unsigned int /*len*/)
{
    m_publicKey = readString(data);
    m_salt = readString(data + (4 + m_publicKey.length()));
}
