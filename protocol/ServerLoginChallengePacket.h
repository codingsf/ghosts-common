#ifndef SERVERLOGINCHALLENGEPACKET_H
#define SERVERLOGINCHALLENGEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ServerLoginChallengePacket : public Packet
{
public:
    static const char Type = 9;
    
    ServerLoginChallengePacket(const std::string &salt = "", const std::string &random = "");
    
    std::string salt() const;
    std::string random() const;
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_salt, m_random;
};

#endif // SERVERLOGINCHALLENGEPACKET_H
