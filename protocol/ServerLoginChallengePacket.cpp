#include "ServerLoginChallengePacket.h"

ServerLoginChallengePacket::ServerLoginChallengePacket(const std::string &salt, const std::string &random) :
    Packet(Type), m_salt(salt), m_random(random)
{
}

std::string ServerLoginChallengePacket::salt() const
{
    return m_salt;
}

std::string ServerLoginChallengePacket::random() const
{
    return m_random;
}

void ServerLoginChallengePacket::read(const char *data)
{
    const char *buf = data;
    
    m_salt = readString(buf);
    buf += 4 + m_salt.length();
    
    m_random = readString(buf);
}

void ServerLoginChallengePacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    
    saveString(buf, m_salt);
    buf += 4 + m_salt.length();
    
    saveString(buf, m_random);
}

int ServerLoginChallengePacket::length() const
{
    return 8 + m_salt.length() + m_random.length();
}
