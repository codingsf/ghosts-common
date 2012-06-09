#include "Packet.h"

Packet::Packet(unsigned char t) :
    m_type(t)
{
}

Packet::~Packet()
{
}

unsigned char Packet::type() const
{
    return m_type;
}
