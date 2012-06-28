#ifndef WELCOMEPACKET_H
#define WELCOMEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT WelcomePacket : public Packet
{
public:
    static const char Type = 11;
    
    WelcomePacket(const UtfString &welcomeMessage = "");
    
    UtfString welcomeMessage() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    UtfString m_welcomeMessage;
};

#endif // WELCOMEPACKET_H
