#include "hblk_crypto.h"
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH])
{
unsigned char *testptr = NULL;
if (strlen((char *)s) > 0)
testptr = SHA256((unsigned char *)s, len, digest);
return (testptr != NULL ? digest : NULL);
}

