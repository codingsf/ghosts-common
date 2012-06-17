#ifndef ERRORPACKET_H
#define ERRORPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ErrorPacket : public Packet
{
public:
    static const char Type = 70;
    
    ErrorPacket();
    ErrorPacket(const std::string &message);
    
    void setMessage(const std::string &message);
    std::string message() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_message;
};

#endif // ERRORPACKET_H
