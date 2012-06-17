#ifndef PLAYERLISTPACKET_H
#define PLAYERLISTPACKET_H

#include "../ghosts-common_global.h"

#include "Packet.h"
#include "PlayerPacket.h"

#include <list>

class GHOSTSCOMMONSHARED_EXPORT PlayerListPacket : public Packet
{
public:
    PlayerListPacket();
    ~PlayerListPacket();
    
    const std::list<PlayerPacket *> &players() const;
    
    void addPlayer(PlayerPacket *player);
    
    virtual void read(const char *data);
    
protected:
    virtual void serializeInternal(char *buffer) const;
    virtual int length() const;
    
private:
    std::list<PlayerPacket *> m_players;
};

#endif // PLAYERLISTPACKET_H
