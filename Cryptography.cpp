#include "Cryptography.h"

#include <crypto++/sha.h>
#include <crypto++/rsa.h>
#include <crypto++/osrng.h>

#include "StringUtils.h"

#include <iostream>

using namespace std;
using namespace CryptoPP;

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
    
    StringSource keySource(key, true);
    publicKey.Load(keySource);
    
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
    
    StringSource keySource(key, true);
    privateKey.Load(keySource);
    
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


