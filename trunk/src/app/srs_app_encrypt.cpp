//
// Created by xiecz on 2018/9/26.
//
#include "srs_app_encrypt.hpp"
#include <cstring>
#include <openssl/aes.h>
#include <new>

static const char _key[AES_BLOCK_SIZE+1] = "1234567890abcdef";

const uint8_t *aes_encode_string(const char* plainText, int& outLen)
{
    AES_KEY key;
    if(AES_set_encrypt_key((uint8_t *)_key, 128, &key) < 0)
    {
        return NULL;
    }

    uint8_t *out_buffer = NULL;
    int plainTextLen = strlen(plainText)+1;

    outLen = plainTextLen % AES_BLOCK_SIZE == 0 ?
             plainTextLen : (plainTextLen/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;
    out_buffer = new(std::nothrow) uint8_t[outLen];

    if(!out_buffer)
    {
        return NULL;
    }

    memset(out_buffer, 0, outLen);
    uint8_t iv[AES_BLOCK_SIZE] = {0};
    AES_cbc_encrypt((uint8_t *)plainText, out_buffer, plainTextLen, &key, iv, AES_ENCRYPT);
    return out_buffer;
}

const char* aes_decode_string(const uint8_t* encrpytData, int length)
{
    AES_KEY key;
    if(AES_set_decrypt_key((uint8_t *)_key, 128, &key) < 0)
    {
        return NULL;
    }

    char *out_buffer = new(std::nothrow) char[length+1];
    if(!out_buffer)
    {
        return NULL;
    }

    memset(out_buffer, 0, length+1);
    uint8_t iv[AES_BLOCK_SIZE] = {0};
    AES_cbc_encrypt(encrpytData, (uint8_t*)out_buffer, length, &key, iv, AES_DECRYPT);
    return out_buffer;
}