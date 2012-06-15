#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include "ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT Cryptography
{
public:
    static std::string digest(const std::string &message);
    
    static std::string encrypt(const std::string &message, const std::string &key);
    static std::string decrypt(const std::string &message, const std::string &key);
    
    static void generateRSAKey(int bits, std::string &privateKey, std::string &publicKey);
    
    static void saveRSAKey(const std::string &filename, const std::string &privateKey);
    static void loadRSAKey(const std::string &filename, std::string &privateKey, std::string &publicKey);
};

#endif // CRYPTOGRAPHY_H
