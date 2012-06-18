#include "GameInvitationPacket.h"

using namespace std;

GameInvitationPacket::GameInvitationPacket(const string &challengerName, const string &challengedName) :
    Packet(Type), m_challengerName(challengerName), m_challengedName(challengedName), 
    m_invitationId(""), m_challengerRating(0.0f)
{
}

string GameInvitationPacket::challengerName() const
{
    return m_challengerName;
}

string GameInvitationPacket::challengedName() const
{
    return m_challengedName;
}

string GameInvitationPacket::invitationId() const
{
    return m_invitationId;
}

float GameInvitationPacket::challengerRating() const
{
    return m_challengerRating;
}

void GameInvitationPacket::setInvitationId(const string &id)
{
    m_invitationId = id;
}

void GameInvitationPacket::setChallengerRating(float r)
{
    m_challengerRating = r;
}

void GameInvitationPacket::read(const char *data)
{
    const char *buf = data;
    
    m_invitationId = readString(buf);
    buf += 4 + m_invitationId.length();
    
    m_challengerName = readString(buf);
    buf += 4 + m_challengerName.length();
    
    m_challengerRating = readFloat(buf);
    buf += 4;
    
    m_challengedName = readString(buf);
}

void GameInvitationPacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    
    saveString(buf, m_invitationId);
    buf += 4 + m_invitationId.length();
    
    saveString(buf, m_challengerName);
    buf += 4 + m_challengerName.length();
    
    saveFloat(buf, m_challengerRating);
    buf += 4;
    
    saveString(buf, m_challengedName);
}

int GameInvitationPacket::length() const
{
    return 16 + m_invitationId.length() + m_challengerName.length() + m_challengedName.length();
}
