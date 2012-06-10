#include "Packet.h"

Packet::Packet(char t) :
    m_type(t)
{
}

Packet::~Packet()
{
}

char Packet::type() const
{
    return m_type;
}
