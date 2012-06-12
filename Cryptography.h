#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <string>

class Cryptography
{
public:
    static std::string digest(const std::string &message);
    
    static std::string encrypt(const std::string &message, unsigned char *key, int length);
    static std::string decrypt(unsigned char *data, int dataLength, unsigned char *key, int keyLength);
};

#endif // CRYPTOGRAPHY_H
