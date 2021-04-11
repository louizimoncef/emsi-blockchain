#ifndef hblk_crypto
#define hblk_crypto
#include<stdint.h>
#include<inttypes.h>
#include <openssl/ssl.h>
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH]);
void _print_hex_buffer(uint8_t const *buf,
size_t len);
#endif

