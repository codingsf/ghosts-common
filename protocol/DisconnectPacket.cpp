#include "DisconnectPacket.h"

DisconnectPacket::DisconnectPacket() :
    Packet(Type)
{
}

void DisconnectPacket::read(const char * /*buffer*/)
{
}

void DisconnectPacket::serializeInternal(char */*buffer*/) const
{
    
}

int DisconnectPacket::length() const
{
    return 0;
}
