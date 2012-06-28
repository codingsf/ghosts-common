#ifndef CHATPACKET_H
#define CHATPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ChatPacket : public Packet
{
public:
    static const char Type = 7;
    
    ChatPacket(const std::string &username = "", const UtfString &message = "");
    
    std::string username() const;
    UtfString message() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_username;
    UtfString m_message;
};

#endif // CHATPACKET_H
