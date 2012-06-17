#ifndef DISCONNECTPACKET_H
#define DISCONNECTPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT DisconnectPacket : public Packet
{
public:
    static const char Type = 13;
    
    DisconnectPacket();
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
};

#endif // DISCONNECTPACKET_H
