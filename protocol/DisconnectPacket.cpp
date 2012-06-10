#include "DisconnectPacket.h"

DisconnectPacket::DisconnectPacket() :
    Packet(Type)
{
}

char *DisconnectPacket::serialize(int &len) const
{
    char *result = new char[1];
    len = 1;
    result[0] = Type;
    
    return result;
}

void DisconnectPacket::read(const char */*data*/, unsigned int /*len*/)
{
}
