#ifndef USERNAMEPACKET_H
#define USERNAMEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT UsernamePacket : public Packet
{
public:
    static const char Register = 1;
    static const char Login = 2;
    
    UsernamePacket(char type);
    
    std::string username() const;
    void setUsername(const std::string &username);
    
    virtual void read(const char *data, unsigned int len);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;    
    
private:
    std::string m_username;
};

#endif // USERNAMEPACKET_H
