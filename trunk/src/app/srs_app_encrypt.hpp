//
// Created by xiecz on 18-9-26.
//

#ifndef SRS_SRS_APP_ENCRYPT_HPP
#define SRS_SRS_APP_ENCRYPT_HPP

#include <stdint.h>

const uint8_t * aes_encode_string(const char* plainText, int& outLen);
const char* aes_decode_string(const uint8_t* encrpytData, int length);

#endif //SRS_SRS_APP_ENCRYPT_HPP
