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
 * block_create - create a block and initialises it
 *@prev: previous  block
 *@data: data to be stored in the block
 *@data_len: length of data
 * Return: a new block structure or NULL
 */
block_t *block_create(block_t const *prev, int8_t const *data,
uint32_t data_len)
{
uint32_t i;
block_t *block = (block_t *) malloc(sizeof(block_t));
if (!prev || !data)
return (NULL);
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(0);
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
if (data_len > (uint32_t)BLOCKCHAIN_DATA_MAX)
block->data.len = BLOCKCHAIN_DATA_MAX;
else
block->data.len = data_len;
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
block->hash[i] = 0;
block->info.difficulty = leadingZeroCalculer(block->hash,
SHA256_DIGEST_LENGTH);
return (block);
}
