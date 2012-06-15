#include "DisconnectPacket.h"

DisconnectPacket::DisconnectPacket() :
    Packet(Type)
{
}

void DisconnectPacket::read(const char */*data*/, unsigned int /*len*/)
{
}

void DisconnectPacket::serializeInternal(char */*buffer*/) const
{
    
}

int DisconnectPacket::length() const
{
    return 0;
}
