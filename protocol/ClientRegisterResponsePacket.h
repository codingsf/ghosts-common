#ifndef CLIENTREGISTERRESPONSEPACKET_H
#define CLIENTREGISTERRESPONSEPACKET_H

#include "Packet.h"

class ClientRegisterResponsePacket : public Packet
{
public:
    static const char Type = 4;
    
    ClientRegisterResponsePacket(const std::string &hashedPassword = "");
    
    std::string hashedPassword() const;
    void setHashedPassword(const std::string &hashedPassword);
    
    virtual char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len);
    
private:
    std::string m_hashedPassword;
};

#endif // CLIENTREGISTERRESPONSEPACKET_H
