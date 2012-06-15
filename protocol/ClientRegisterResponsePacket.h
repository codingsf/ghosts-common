#ifndef CLIENTREGISTERRESPONSEPACKET_H
#define CLIENTREGISTERRESPONSEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ClientRegisterResponsePacket : public Packet
{
public:
    static const char Type = 4;
    
    ClientRegisterResponsePacket(const std::string &hashedPassword = "");
    
    std::string hashedPassword() const;
    void setHashedPassword(const std::string &hashedPassword);
    
    virtual void read(const char *data, unsigned int len);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;    
    
private:
    std::string m_hashedPassword;
};

#endif // CLIENTREGISTERRESPONSEPACKET_H
