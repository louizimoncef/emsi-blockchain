#include "hblk_crypto.h"
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH])
{
if (strlen((char*)s) > 0)
{
SHA256_CTX ctx;
SHA256_Init(&ctx);
SHA256_Update(&ctx, s, len);
SHA256_Final(digest, &ctx);
}
return (digest != NULL ? digest : NULL);
}
