#ifndef SERVERREGISTERCHALLENGEPACKET_H
#define SERVERREGISTERCHALLENGEPACKET_H

#include "Packet.h"

class ServerRegisterChallengePacket : public Packet
{
public:
    static const char Type = 3;
    
    ServerRegisterChallengePacket(const std::string &publicKey = "", const std::string &salt = "");
    
    std::string publicKey() const;
    std::string salt() const;
    
    void setPublicKey(const std::string &publicKey);
    void setSalt(const std::string &salt);
    
    virtual char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len);
    
private:
    std::string m_publicKey, m_salt;
};

#endif // SERVERREGISTERCHALLENGEPACKET_H
