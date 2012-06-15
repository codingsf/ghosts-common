#ifndef SERVERREGISTERCHALLENGEPACKET_H
#define SERVERREGISTERCHALLENGEPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT ServerRegisterChallengePacket : public Packet
{
public:
    static const char Type = 3;
    
    ServerRegisterChallengePacket(const std::string &publicKey = "", const std::string &salt = "");
    
    std::string publicKey() const;
    std::string salt() const;
    
    void setPublicKey(const std::string &publicKey);
    void setSalt(const std::string &salt);
    
    virtual void read(const char *data, unsigned int len);

protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_publicKey, m_salt;
};

#endif // SERVERREGISTERCHALLENGEPACKET_H
