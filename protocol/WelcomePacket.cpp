#include "WelcomePacket.h"

WelcomePacket::WelcomePacket(const UtfString &welcomeMessage) :
    Packet(Type), m_welcomeMessage(welcomeMessage)
{
}

UtfString WelcomePacket::welcomeMessage() const
{
    return m_welcomeMessage;
}

void WelcomePacket::read(const char *data)
{
    m_welcomeMessage = readUtfString(data);
}

void WelcomePacket::serializeInternal(char *buffer) const
{
    saveUtfString(buffer, m_welcomeMessage);
}

int WelcomePacket::length() const
{
    return 4 + 4*m_welcomeMessage.length();
}
