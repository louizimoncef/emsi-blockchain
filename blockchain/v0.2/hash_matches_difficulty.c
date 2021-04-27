#include "blockchain.h"
uint32_t leadingZeroCalculer(uint8_t const *hash,size_t len)
{
uint8_t n, i = 0, x;
uint32_t res = 0;
if(hash)
{
for(i = 0; i < len ; i++)
{
x=hash[i];
for(n=0; n < 8; n++)
{
if((x & 0x80) != 0)
{
return (res);
}
x = x << 1;
res++;
}
}
}
return (-1);
}
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty)
{
return (leadingZeroCalculer(hash, SHA256_DIGEST_LENGTH) == difficulty ? 1:0);
}
