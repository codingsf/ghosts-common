#include "PlayerPacket.h"

PlayerPacket::PlayerPacket(const std::string &username, float rating, bool playing) :
    m_username(username), m_rating(rating), m_playing(playing)
{
}

std::string PlayerPacket::username() const
{
    return m_username;
}

float PlayerPacket::rating() const
{
    return m_rating;
}

bool PlayerPacket::playing() const
{
    return m_playing;
}

void PlayerPacket::serializeExternal(char *buffer) const
{
    serializeInternal(buffer);
}

int PlayerPacket::lengthExternal() const
{
    return length();
}

void PlayerPacket::read(const char *data)
{
    const char *buf = data;
    
    m_username = readString(buf);
    buf += 4 + m_username.length();
    
    m_rating = readFloat(buf);
    buf += 4;
    
    m_playing = readBool(buf);
}

void PlayerPacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    
    saveString(buf, m_username);
    buf += 4 + m_username.length();
    
    saveFloat(buf, m_rating);
    buf += 4;
    
    saveBool(buf, m_playing);
}

int PlayerPacket::length() const
{
    return m_username.length() + 9;
}
