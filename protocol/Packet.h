#ifndef PACKET_H
#define PACKET_H

#include "../ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT UtfString
{
public:
    UtfString(const char *text);
    UtfString(const std::string &text);
    UtfString(const std::wstring &text);
    UtfString(const unsigned int *codes, unsigned int length);
    
    UtfString(const UtfString &other);
    
    ~UtfString();
    
    std::string toString() const;
    std::wstring toWString() const;
    char *toCharArray() const;
    
    unsigned int at(unsigned int i) const;
    
    unsigned int length() const;
    
    UtfString &operator=(const UtfString &other);
    
private:
    unsigned int m_length;
    unsigned int *m_characters;
};

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
    
    static void saveBool(char *buffer, bool value);
    static bool readBool(const char *buffer);
    
    static void saveWString(char *buffer, const std::wstring &text);
    static std::wstring readWString(const char *buffer);
    
    static void saveWChar(char *buffer, wchar_t character);
    static wchar_t readWChar(const char *buffer);
    
    static void saveUtfString(char *buffer, const UtfString &text);
    static UtfString readUtfString(const char *buffer);
    
    Packet(char t = Invalid);
    virtual ~Packet();
    
    char type() const;
    
    char *serialize(int &len) const;
    virtual void read(const char *data) = 0;
    
protected:
    char m_type;
    
    virtual void serializeInternal(char *buffer) const = 0;
    virtual int length() const = 0;

};

#endif // PACKET_H
