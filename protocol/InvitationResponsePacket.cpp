#include "InvitationResponsePacket.h"

InvitationResponsePacket::InvitationResponsePacket(const std::string &username, const std::string &invitationId, bool accepted) :
    Packet(Type), m_username(username), m_invitationId(invitationId), m_accepted(accepted)
{
}

std::string InvitationResponsePacket::username() const
{
    return m_username;
}

std::string InvitationResponsePacket::invitationId() const
{
    return m_invitationId;
}

bool InvitationResponsePacket::accepted() const
{
    return m_accepted;
}

void InvitationResponsePacket::read(const char *data)
{
    const char *buf = data;
    
    m_username = readString(buf);
    buf += 4 + m_username.length();
    
    m_invitationId = readString(buf);
    buf += 4 + m_invitationId.length();
    
    m_accepted = readBool(buf);
}

void InvitationResponsePacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    
    saveString(buf, m_username);
    buf += 4 + m_username.length();
    
    saveString(buf, m_invitationId);
    buf += 4 + m_invitationId.length();
    
    saveBool(buf, m_accepted);
}

int InvitationResponsePacket::length() const
{
    return 9 + m_username.length() + m_invitationId.length();
}
