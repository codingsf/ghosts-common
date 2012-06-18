#-------------------------------------------------
#
# Project created by QtCreator 2012-06-08T15:38:14
#
#-------------------------------------------------

CONFIG -= qt

TARGET = ghosts-common
TEMPLATE = lib

DESTDIR = ../lib

LIBS += -lcrypto++

DEFINES += GHOSTSCOMMON_LIBRARY

SOURCES += \
    Logger.cpp \
    Environment.cpp \
    Random.cpp \
    protocol/Packet.cpp \
    protocol/DisconnectPacket.cpp \
    Cryptography.cpp \
    StringUtils.cpp \
    protocol/UsernamePacket.cpp \
    protocol/ErrorPacket.cpp \
    protocol/ServerRegisterChallengePacket.cpp \
    protocol/ClientRegisterResponsePacket.cpp \
    protocol/PlayerPacket.cpp \
    protocol/PlayerListPacket.cpp \
    protocol/ChatPacket.cpp \
    protocol/GameInvitationPacket.cpp \
    protocol/InvitationResponsePacket.cpp

HEADERS +=\
        ghosts-common_global.h \
    Logger.h \
    Environment.h \
    Random.h \
    protocol/Packet.h \
    protocol/DisconnectPacket.h \
    Cryptography.h \
    StringUtils.h \
    protocol/UsernamePacket.h \
    protocol/ErrorPacket.h \
    protocol/ServerRegisterChallengePacket.h \
    protocol/ClientRegisterResponsePacket.h \
    protocol/PlayerPacket.h \
    protocol/PlayerListPacket.h \
    protocol/ChatPacket.h \
    protocol/GameInvitationPacket.h \
    protocol/InvitationResponsePacket.h
