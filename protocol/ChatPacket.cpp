#include "ChatPacket.h"

using namespace std;

ChatPacket::ChatPacket(const string &username, const wstring &message) :
    Packet(Type), m_username(username), m_message(message)
{
}

string ChatPacket::username() const
{
    return m_username;
}

wstring ChatPacket::message() const
{
    return m_message;
}

void ChatPacket::read(const char *data)
{
    const char *buf = data;
    m_username = readString(buf);
    buf += 4 + m_username.length();
    
    m_message = readWString(buf);
}

void ChatPacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    saveString(buf, m_username);
    buf += 4 + m_username.length();
    
    saveWString(buf, m_message);
}

int ChatPacket::length() const
{
    return 8 + m_username.length() + 2*m_message.length();
}
