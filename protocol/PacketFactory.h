#ifndef PACKETFACTORY_H
#define PACKETFACTORY_H

#include "Packet.h"

class PacketFactory
{
public:
    static Packet *getPacket(char id);
};

#endif // PACKETFACTORY_H
