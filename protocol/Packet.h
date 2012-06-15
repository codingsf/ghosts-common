#ifndef PACKET_H
#define PACKET_H

#include "../ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT Packet
{
public:
    static const char Invalid = -1;
    static const int MaximalPacketSize = 3072;

    static void saveInt(char *buffer, int number);
    static int readInt(const char *buffer);
    
    static void saveFloat(char *buffer, float number);
    static float readFloat(const char *buffer);
    
    static void saveString(char *buffer, const std::string &text);
    static std::string readString(const char *buffer);
    
    Packet(char t = Invalid);
    virtual ~Packet();
    
    char type() const;
    
    char *serialize(int &len) const;
    virtual void read(const char *data, unsigned int len) = 0;
    
protected:
    char m_type;
    
    virtual void serializeInternal(char *buffer) const = 0;
    virtual int length() const = 0;

};

#endif // PACKET_H
