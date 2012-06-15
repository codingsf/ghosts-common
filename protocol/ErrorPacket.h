#ifndef ERRORPACKET_H
#define ERRORPACKET_H

#include "Packet.h"

class ErrorPacket : public Packet
{
public:
    static const char Type = 70;
    
    ErrorPacket();
    ErrorPacket(const std::string &message);
    
    void setMessage(const std::string &message);
    std::string message() const;
    
    virtual char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len);
    
private:
    std::string m_message;
};

#endif // ERRORPACKET_H
