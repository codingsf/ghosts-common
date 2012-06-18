#ifndef GAMEINVITATIONPACKET_H
#define GAMEINVITATIONPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT GameInvitationPacket : public Packet
{
public:
    static const char Type = 8;
    
    GameInvitationPacket(const std::string &challengerName = "", const std::string &challengedName = "");
    
    std::string challengerName() const;
    std::string challengedName() const;
    std::string invitationId() const;
    float challengerRating() const;
    
    void setInvitationId(const std::string &id);
    void setChallengerRating(float r);
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_challengerName, m_challengedName, m_invitationId;
    float m_challengerRating;
};

#endif // GAMEINVITATIONPACKET_H
