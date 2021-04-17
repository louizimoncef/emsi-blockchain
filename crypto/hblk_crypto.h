#ifndef hblk_crypto
#define hblk_crypto
#include<stdint.h>
#include<inttypes.h>
#include <openssl/ssl.h>
#include <openssl/sha.h>
#define EC_PUB_LEN 65
#define EC_CURVE	NID_secp256k1
#define PRK_FN "key.pem"
#define PUK_FN "key_pub.pem"
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
#endif
