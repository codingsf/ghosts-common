#include "Cryptography.h"

#include <crypto++/sha.h>
#include <crypto++/rsa.h>
#include <crypto++/osrng.h>
#include <crypto++/files.h>

#include "StringUtils.h"

#include <iostream>

using namespace std;
using namespace CryptoPP;

// helpers
void parsePrivateKey(const string &key, RSA::PrivateKey &privateKey)
{
    StringSource keySource(key, true);
    privateKey.Load(keySource);  
}

void parsePublicKey(const string &key, RSA::PublicKey &publicKey)
{
    StringSource keySource(key, true);
    publicKey.Load(keySource);
}

string Cryptography::digest(const string &message)
{
    SHA512 algorithm;
    
    byte *digest = new byte[algorithm.DigestSize()];
    
    algorithm.CalculateDigest(digest, (const byte *)message.c_str(), message.length());
    
    string result = StringUtils::bytesToString(digest, algorithm.DigestSize());
    
    delete [] digest;
    
    return result;
}



string Cryptography::encrypt(const string &message, const string &key)
{
    RSA::PublicKey publicKey;
    AutoSeededRandomPool rng;
    
    parsePublicKey(key, publicKey);
    
    string result;
    
    RSAES_OAEP_SHA_Encryptor encryptor(publicKey);
    
    StringSource(message, true,
                 new PK_EncryptorFilter(rng, encryptor, new StringSink(result)));
    
    return result;
}

string Cryptography::decrypt(const string &message, const string &key)
{
    RSA::PrivateKey privateKey;
    AutoSeededRandomPool rng;
    
    parsePrivateKey(key, privateKey);
    
    string result;
    
    RSAES_OAEP_SHA_Decryptor decryptor(privateKey);
    
    StringSource(message, true, new PK_DecryptorFilter(rng, decryptor, new StringSink(result)));
    
    return result;
}

void Cryptography::generateRSAKey(int bits, string &privateKey, string &publicKey)
{
    AutoSeededRandomPool rng;
    privateKey = publicKey = "";
    
    InvertibleRSAFunction parameters;
    parameters.GenerateRandomWithKeySize(rng, bits);
    
    RSA::PrivateKey privKey(parameters);
    RSA::PublicKey pubKey(parameters);
    
    StringSink privateKeySink(privateKey), publicKeySink(publicKey);
    privKey.Save(privateKeySink);
    pubKey.Save(publicKeySink);
}

void Cryptography::saveRSAKey(const string &filename, const string &privateKey)
{
    RSA::PrivateKey pKey;
    
    parsePrivateKey(privateKey, pKey);
    FileSink fs(filename.c_str());
    pKey.Save(fs);
}

void Cryptography::loadRSAKey(const string &filename, string &privateKey, string &publicKey)
{
    RSA::PrivateKey pKey;
    
    FileSource fs(filename.c_str(), true);
    pKey.Load(fs);
    
    RSA::PublicKey pubKey(pKey);
    
    StringSink ss(privateKey), ssPub(publicKey);
    pKey.Save(ss);
    pubKey.Save(ssPub);
}


