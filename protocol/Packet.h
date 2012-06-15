#ifndef PACKET_H
#define PACKET_H

#include "../ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT Packet
{
public:
    static const char Invalid = -1;
    static const int MaximalPacketSize = 3072;
    
    Packet(char t = Invalid);
    virtual ~Packet();
    
    char type() const;
    
    virtual char *serialize(int &len) const = 0;
    virtual void read(const char *data, unsigned int len) = 0;
    
protected:
    char m_type;
    
    void saveInt(char *buffer, int number) const;
    int readInt(const char *buffer);
    
    void saveFloat(char *buffer, float number) const;
    float readFloat(const char *buffer);
    
    void saveString(char *buffer, const std::string &text) const;
    std::string readString(const char *buffer);
};

#endif // PACKET_H
