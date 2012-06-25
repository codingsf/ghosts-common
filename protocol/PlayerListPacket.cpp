#include "PlayerListPacket.h"

using namespace std;

PlayerListPacket::PlayerListPacket() :
    Packet(Type)
{
}

PlayerListPacket::~PlayerListPacket()
{
    for(list<PlayerPacket *>::iterator iter = m_players.begin(); iter != m_players.end(); iter++)
        delete (*iter);
    
    m_players.clear();
}

const list<PlayerPacket *> &PlayerListPacket::players() const
{
    return m_players;
}

void PlayerListPacket::addPlayer(PlayerPacket *player)
{
    if(player != 0)
        m_players.push_back(player);
}

void PlayerListPacket::read(const char */*data*/)
{
}

void PlayerListPacket::serializeInternal(char *buffer) const
{
    saveInt(buffer, m_players.size());
}

int PlayerListPacket::length() const
{
    return 4;
}
