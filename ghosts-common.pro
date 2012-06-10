#-------------------------------------------------
#
# Project created by QtCreator 2012-06-08T15:38:14
#
#-------------------------------------------------

CONFIG -= qt

TARGET = ghosts-common
TEMPLATE = lib

DESTDIR = ../lib

DEFINES += GHOSTSCOMMON_LIBRARY

SOURCES += \
    Logger.cpp \
    Environment.cpp \
    Random.cpp \
    protocol/Packet.cpp \
    protocol/DisconnectPacket.cpp

HEADERS +=\
        ghosts-common_global.h \
    Logger.h \
    Environment.h \
    Random.h \
    protocol/Packet.h \
    protocol/DisconnectPacket.h
