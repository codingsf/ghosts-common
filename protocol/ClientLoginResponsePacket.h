#ifndef CLIENTLOGINRESPONSEPACKET_H
#define CLIENTLOGINRESPONSEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ClientLoginResponsePacket : public Packet
{
public:
    static const char Type = 10;
    
    ClientLoginResponsePacket(const std::string &response = "");
    
    std::string response() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_response;
        
};

#endif // CLIENTLOGINRESPONSEPACKET_H
