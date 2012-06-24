#ifndef INVITATIONRESPONSEPACKET_H
#define INVITATIONRESPONSEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT InvitationResponsePacket : public Packet
{
public:
    static const char Type = 9;
    
    InvitationResponsePacket(const std::string &username = "", const std::string &invitationId = "", bool accepted = false);
    
    std::string username() const;
    std::string invitationId() const;
    bool accepted() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_username, m_invitationId;
    bool m_accepted;
};

#endif // INVITATIONRESPONSEPACKET_H
