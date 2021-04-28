#include "blockchain.h"
/**
 * leadingZeroCalculer - calculute number of leading  zero in
 * the chain bits of hash
 * @hash: lhe hash
 * @len: The lenght de hash
 * Return: number of leadingZero  success, -1  failure
 */
uint32_t leadingZeroCalculer(uint8_t const *hash, size_t len)
{
uint8_t n, i = 0, x;
uint32_t res = 0;
uint8_t hash_test[SHA256_DIGEST_LENGTH];
if (hash)
{
memset(hash_test, 0, SHA256_DIGEST_LENGTH);
if (memcmp(hash, hash_test, SHA256_DIGEST_LENGTH) == 0)
return (256);
for (i = 0; i < len ; i++)
{
x = hash[i];
for (n = 0; n < 8; n++)
{
if ((x & 0x80) != 0)
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
/**
 * hash_matches_difficulty - check if difficulty matches
 * the  hash
 * @hash: The hash
 * @difficulty: The difficulty
 * Return: 0  success, -1  failure
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
return (leadingZeroCalculer(hash, SHA256_DIGEST_LENGTH) == difficulty ? 1 : 0);
}
