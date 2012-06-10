#ifndef DISCONNECTPACKET_H
#define DISCONNECTPACKET_H

#include "Packet.h"

class DisconnectPacket : public Packet
{
public:
    static const char Type = 13;
    
    DisconnectPacket();
    
    virtual char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len);
};

#endif // DISCONNECTPACKET_H
