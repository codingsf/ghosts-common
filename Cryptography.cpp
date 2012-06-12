#include "Cryptography.h"

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include "StringUtils.h"

#include <iostream>

using namespace std;

string Cryptography::digest(const string &message)
{
    EVP_MD_CTX *context;
    const EVP_MD *md = EVP_sha512();
    
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int length;
    
    context = EVP_MD_CTX_create();
    EVP_DigestInit_ex(context, md, NULL);
    
    EVP_DigestUpdate(context, message.c_str(), message.length());
    
    EVP_DigestFinal_ex(context, digest, &length);
    EVP_MD_CTX_destroy(context);
    
    return StringUtils::bytesToString(digest, length);
}

string Cryptography::encrypt(const string &message, unsigned char *key, int length)
{
    RSA *rsa;
    
    BIO *bio = BIO_new_mem_buf(key, length);
    PEM_read_bio_RSAPublicKey(bio, &rsa, NULL, NULL);
    
    cout << ERR_error_string(ERR_get_error(), NULL) << endl;
    
    unsigned char *result = new unsigned char[RSA_size(rsa)];
    
    int encryptedSize = RSA_public_encrypt(message.length(), 
                                           (const unsigned char *)message.c_str(),
                                           result,
                                           rsa, RSA_PKCS1_PADDING);
    BIO_free(bio);
    RSA_free(rsa);
    
    string r = StringUtils::bytesToString(result, encryptedSize);
    
    delete [] result;
    
    return r;
}

string Cryptography::decrypt(unsigned char *data, int dataLength, unsigned char *key, int keyLength)
{
    RSA *rsa;
    
    BIO *bio = BIO_new_mem_buf(key, keyLength);
    rsa = PEM_read_bio_RSAPrivateKey(bio, &rsa, NULL, NULL);
    BIO_free(bio);
    
    unsigned char *result = new unsigned char[RSA_size(rsa)];
    
    int decryptedSize = RSA_private_decrypt(dataLength, data, result, rsa, RSA_PKCS1_PADDING);
    
    RSA_free(rsa);
    
    result[decryptedSize] = 0;
    string r = string((const char *)result);
    
    delete [] result;
    
    return r;
}

unsigned char *Cryptography::extractPublicKey(unsigned char *key, int length, int &pkeyLen)
{
    BIO *bio = BIO_new(BIO_s_mem());
    
    RSA *rsa;
    
    BIO *keyBio = BIO_new_mem_buf(key, length);
    rsa = PEM_read_bio_RSAPublicKey(keyBio, &rsa, NULL, NULL);
    BIO_free(keyBio);
    
    PEM_write_bio_RSAPublicKey(bio, rsa);
    RSA_free(rsa);
    
    pkeyLen = BIO_ctrl_pending(bio);
    
    unsigned char *result = new unsigned char[pkeyLen];
    BIO_read(bio, result, pkeyLen);
    BIO_free(bio);
    
    return result;
}

