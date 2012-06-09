#ifndef PACKET_H
#define PACKET_H

#include "../ghosts-common_global.h"

class GHOSTSCOMMONSHARED_EXPORT Packet
{
public: 
    static const unsigned char Invalid = -1;
    
    Packet(unsigned char t = Invalid);
    virtual ~Packet();
    
    unsigned char type() const;
    
    virtual char *serialize() const = 0;
    virtual void read(const char *data, unsigned int len) = 0;
    
protected:
    unsigned char m_type;
};

#endif // PACKET_H
