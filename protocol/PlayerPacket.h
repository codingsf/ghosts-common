#ifndef PLAYERPACKET_H
#define PLAYERPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"

class GHOSTSCOMMONSHARED_EXPORT PlayerPacket : public Packet
{
public:
    static const char Type = 5;
    
    PlayerPacket(const std::string &username = "", float rating = 1000.0, bool playing = false);
    
    std::string username() const;
    float rating() const;
    bool playing() const;
    
    virtual void read(const char *data);
    
protected:
    void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::string m_username;
    float m_rating;
    bool m_playing;
};

#endif // PLAYERPACKET_H
