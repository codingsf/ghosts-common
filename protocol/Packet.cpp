#include "Packet.h"

#include <cstring>

using namespace std;

Packet::Packet(char t) :
    m_type(t)
{
}

Packet::~Packet()
{
}

char Packet::type() const
{
    return m_type;
}

char *Packet::serialize(int &len) const
{
    len = length() + 5;
            
    char *result = new char[len];
    char *buffer = result;
    
    saveInt(buffer, len);
    buffer += 4;
    buffer[0] = m_type;
    buffer += 1;
    
    serializeInternal(buffer);
    
    return result;
}

void Packet::saveInt(char *buffer, int number)
{
    char *bufNum = (char *)&number;
    
    for(int i = 0; i < 4; i++)
        buffer[i] = bufNum[i];
}

int Packet::readInt(const char *buffer)
{
    int result;
    
    char *bufRes = (char *)&result;
    
    for(int i = 0; i < 4; i++)
        bufRes[i] = buffer[i];
    
    return result;
}

void Packet::saveFloat(char *buffer, float number)
{
    char *bufNum = (char *)&number;
    
    for(int i = 0; i < 4; i++)
        buffer[i] = bufNum[i];
}

float Packet::readFloat(const char *buffer)
{
    float result;
    
    char *bufRes = (char *)&result;
    
    for(int i = 0; i < 4; i++)
        bufRes[i] = buffer[i];
    
    return result;
}

void Packet::saveString(char *buffer, const string &text)
{
    saveInt(buffer, text.length());
    
    char *buf = buffer + 4;
    
    for(int i = 0; i < (int)text.length(); i++)
        buf[i] = text.at(i);
}

string Packet::readString(const char *buffer)
{
    int length = readInt(buffer);
    const char *buf = buffer + 4;
    
    string result;
    
    for(int i = 0; i < length; i++)
        result.append(1, buf[i]);
    
    return result;
}

void Packet::saveBool(char *buffer, bool value)
{
    *buffer = (value?1:0);
}

bool Packet::readBool(const char *buffer)
{
    return (*buffer) != 0;
}

void Packet::saveWString(char *buffer, const wstring &text)
{
    char *buf = buffer;
    
    saveInt(buf, text.length());
    buf += 4;
    
    for(unsigned int i = 0; i < text.length(); i++)
    {
        saveWChar(buf, text.at(i));
        buf += 2;
    }
}

wstring Packet::readWString(const char *buffer)
{
    const char *buf = buffer;
    
    int size = readInt(buf);
    buf += 4;
    
    wstring result = L"";
    
    for(int i = 0; i < size; i++)
    {
        wchar_t character = readWChar(buf);
        buf += 2;
        result.append(1, character);
    }
    
    return result;
}

void Packet::saveWChar(char *buffer, wchar_t character)
{
    const char *b = (const char *)&character;
    
    buffer[0] = b[0];
    buffer[1] = b[1];
}

wchar_t Packet::readWChar(const char *buffer)
{
    wchar_t result;
    
    char *b = (char *)&result;
    
    b[0] = buffer[0];
    b[1] = buffer[1];
    
    return result;
}

void Packet::saveUtfString(char *buffer, const UtfString &text)
{
    char *buf = buffer;
    
    saveInt(buf, text.length());
    buf += 4;
    
    for(unsigned int i = 0; i < text.length(); i++)
    {
        saveInt(buf, text.at(i));
        buf += 4;
    }
}

UtfString Packet::readUtfString(const char *buffer)
{
    const char *buf = buffer;
    
    unsigned int length = readInt(buf);
    buf += 4;
    
    unsigned int *characters = new unsigned int[length];
    
    for(unsigned int i = 0; i < length; i++)
    {
        characters[i] = readInt(buf);
        buf += 4;
    }
    
    UtfString result(characters, length);
    delete [] characters;
    
    return result;
}

UtfString::UtfString(const char *text)
{
    m_length = strlen(text);
    
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = (unsigned int)text[i];
}

UtfString::UtfString(const string &text)
{
    m_length = text.length();
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = (unsigned int)text.at(i);
}

UtfString::UtfString(const wstring &text)
{
    m_length = text.length();
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = (unsigned int)text.at(i);
}

UtfString::UtfString(const unsigned int *codes, unsigned int length)
{
    m_length = length;
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = codes[i];
}

UtfString::UtfString(const UtfString &other)
{
    m_length = other.m_length;
    
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = other.m_characters[i];
}

UtfString::~UtfString()
{
    delete [] m_characters;
}

string UtfString::toString() const
{
    string result = "";
    for(unsigned int i = 0; i < m_length; i++)
        result.append(1, (char)m_characters[i]);
    
    return result;
}

wstring UtfString::toWString() const
{
    wstring result = L"";
    
    for(unsigned int i = 0; i < m_length; i++)
        result.append(1, (wchar_t)m_characters[i]);
    
    return result;
}

char *UtfString::toCharArray() const
{
    char *result = new char[m_length + 1];
    
    for(unsigned int i = 0; i < m_length; i++)
        result[i] = (char)m_characters[i];
    
    result[m_length] = 0;
    
    return result;
}

unsigned int UtfString::at(unsigned int i) const
{
    if(i < m_length)
        return m_characters[i];
    
    return 0;
}

unsigned int UtfString::length() const
{
    return m_length;
}

UtfString &UtfString::operator =(const UtfString &other)
{
    delete [] m_characters;
    
    m_length = other.m_length;
    m_characters = new unsigned int[m_length];
    
    for(unsigned int i = 0; i < m_length; i++)
        m_characters[i] = other.m_characters[i];
    
    return *this;
}
