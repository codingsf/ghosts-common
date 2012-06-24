#include "PacketFactory.h"

#include "ChatPacket.h"
#include "ClientLoginResponsePacket.h"
#include "ClientRegisterResponsePacket.h"
#include "DisconnectPacket.h"
#include "ErrorPacket.h"
#include "GameInvitationPacket.h"
#include "InvitationResponsePacket.h"
#include "PlayerListPacket.h"
#include "ServerLoginChallengePacket.h"
#include "ServerRegisterChallengePacket.h"
#include "UsernamePacket.h"
#include "WelcomePacket.h"

Packet *PacketFactory::getPacket(char id)
{
    switch(id)
    {
    case ChatPacket::Type:
        return new ChatPacket();
    case ClientLoginResponsePacket::Type:
        return new ClientLoginResponsePacket();
    case ClientRegisterResponsePacket::Type:
        return new ClientRegisterResponsePacket();
    case DisconnectPacket::Type:
        return new DisconnectPacket();
    case ErrorPacket::Type:
        return new ErrorPacket();
    case GameInvitationPacket::Type:
        return new GameInvitationPacket();
    case InvitationResponsePacket::Type:
        return new InvitationResponsePacket();
    case PlayerListPacket::Type:
        return new PlayerListPacket();
    case PlayerPacket::Type:
        return new PlayerPacket();
    case ServerLoginChallengePacket::Type:
        return new ServerLoginChallengePacket();
    case ServerRegisterChallengePacket::Type:
        return new ServerRegisterChallengePacket();
    case UsernamePacket::Register:
    case UsernamePacket::Login:
        return new UsernamePacket(id);
    case WelcomePacket::Type:
        return new WelcomePacket();
    default:
        return 0;
    }
}
