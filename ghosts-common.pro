#-------------------------------------------------
#
# Project created by QtCreator 2012-06-08T15:38:14
#
#-------------------------------------------------

QT       -= core gui

TARGET = ghosts-common
TEMPLATE = lib

DEFINES += GHOSTSCOMMON_LIBRARY

SOURCES +=

HEADERS +=\
        ghosts-common_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE8B1E116
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ghosts-common.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
