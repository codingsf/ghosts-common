#include "ClientLoginResponsePacket.h"

ClientLoginResponsePacket::ClientLoginResponsePacket(const std::string &response) :
    Packet(Type), m_response(response)
{
}

std::string ClientLoginResponsePacket::response() const
{
    return m_response;
}

void ClientLoginResponsePacket::read(const char *data)
{
    m_response = readString(data);
}

void ClientLoginResponsePacket::serializeInternal(char *buffer) const
{
    saveString(buffer, m_response);
}

int ClientLoginResponsePacket::length() const
{
    return 4 + m_response.length();
}
