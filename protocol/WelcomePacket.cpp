#include "WelcomePacket.h"

WelcomePacket::WelcomePacket(const std::wstring &welcomeMessage) :
    Packet(Type), m_welcomeMessage(welcomeMessage)
{
}

std::wstring WelcomePacket::welcomeMessage() const
{
    return m_welcomeMessage;
}

void WelcomePacket::read(const char *data)
{
    m_welcomeMessage = readWString(data);
}

void WelcomePacket::serializeInternal(char *buffer) const
{
    saveWString(buffer, m_welcomeMessage);
}

int WelcomePacket::length() const
{
    return 4 + 2*m_welcomeMessage.length();
}
