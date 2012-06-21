#include "WelcomePacket.h"

WelcomePacket::WelcomePacket(const std::string &welcomeMessage) :
    Packet(Type), m_welcomeMessage(welcomeMessage)
{
}

std::string WelcomePacket::welcomeMessage() const
{
    return m_welcomeMessage;
}

void WelcomePacket::read(const char *data)
{
    m_welcomeMessage = readString(data);
}

void WelcomePacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_welcomeMessage);
}

int WelcomePacket::length() const
{
    return 4 + m_welcomeMessage.length();
}
