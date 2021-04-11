#include "hblk_crypto.h"
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH])
{
if (s)
{
unsigned int mt_len;
SHA256_CTX *mdctx;
const EVP_MD *md;
md = EVP_sha256();
mdctx =(SHA256_CTX *) EVP_MD_CTX_create();
EVP_DigestInit_ex((SHA256_CTX *)mdctx, md, NULL);
EVP_DigestUpdate((SHA256_CTX *)mdctx, s, len);
EVP_DigestFinal_ex((SHA256_CTX *)mdctx, digest, &mt_len);
EVP_MD_CTX_destroy((SHA256_CTX *)mdctx);
EVP_cleanup();
}
return (digest ? digest : NULL);
}
