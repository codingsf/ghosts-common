#include "ErrorPacket.h"

ErrorPacket::ErrorPacket() :
    Packet(Type), m_message("No error - WTF?")
{
}

ErrorPacket::ErrorPacket(const std::string &message) :
    Packet(Type), m_message(message)
{
}

void ErrorPacket::setMessage(const std::string &message)
{
    m_message = message;
}

std::string ErrorPacket::message() const
{
    return m_message;
}

void ErrorPacket::read(const char *data, unsigned int /*len*/)
{
    m_message = readString(data);
}

void ErrorPacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_message);
}

int ErrorPacket::length() const
{
    return 4 + m_message.length();
}
