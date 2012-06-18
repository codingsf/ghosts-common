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

void PlayerListPacket::read(const char *data)
{
    const char *buf = data;
    int size = readInt(buf);
    buf += 4;
    
    PlayerPacket *player;
    
    for(int i = 0; i < size; i++)
    {
        player = new PlayerPacket();
        player->read(buf);
        buf += player->lengthExternal();
        m_players.push_back(player);
    }
}

void PlayerListPacket::serializeInternal(char *buffer) const
{
    char *buf = buffer;
    saveInt(buf, m_players.size());
    buf += 4;
    
    for(list<PlayerPacket *>::const_iterator iter = m_players.begin(); iter != m_players.end(); iter++)
    {
        (*iter)->serializeExternal(buf);
        buf += (*iter)->lengthExternal();
    }
}

int PlayerListPacket::length() const
{
    int result = 4;
    
    for(list<PlayerPacket *>::const_iterator iter = m_players.begin(); iter != m_players.end(); iter++)
        result += (*iter)->lengthExternal();
    
    return result;
}
