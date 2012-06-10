#ifndef PACKET_H
#define PACKET_H

#include "../ghosts-common_global.h"

class GHOSTSCOMMONSHARED_EXPORT Packet
{
public:
    static const char Invalid = -1;
    static const int MaximalPacketSize = 3072;
    
    Packet(char t = Invalid);
    virtual ~Packet();
    
    char type() const;
    
    virtual char *serialize(int &len) const = 0;
    virtual void read(const char *data, unsigned int len) = 0;
    
protected:
    char m_type;
};

#endif // PACKET_H
