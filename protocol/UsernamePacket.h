#ifndef USERNAMEPACKET_H
#define USERNAMEPACKET_H

#include "Packet.h"

class UsernamePacket : public Packet
{
public:
    static const char Register = 1;
    static const char Login = 2;
    
    UsernamePacket(char type);
    
    std::string username() const;
    void setUsername(const std::string &username);
    
    virtual char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len);
    
private:
    std::string m_username;
};

#endif // USERNAMEPACKET_H
