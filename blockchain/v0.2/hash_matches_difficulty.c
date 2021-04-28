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
uint8_t n, x, c, res = 0, i;
bool is_one = false;
for (i = 0 ; i < len ; i++)
{
n = hash[i];
x = n;
for (c = 0; c < 8; c++)
{
if (!c && !i && (n & 1))
return (0);
else if (n & 1)
is_one = true;
else
res++;
n = n >> 1;
}
if (is_one)
return (res);
return (-1);
}
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
