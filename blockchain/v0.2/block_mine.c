#include "blockchain.h"
/**
 * block_mine - mining by changing the nonce
 * @block: the mined block
 */
void block_mine(block_t *block)
{
if (!hash_matches_difficulty(blockHash, block->info.difficulty))
{
uint8_t blockHash[SHA256_DIGEST_LENGTH];
block_hash(block, blockHash);
while (!hash_matches_difficulty(blockHash, block->info.difficulty))
{
block->info.nonce++;
block_hash(block, blockHash);
}
memcpy(block->hash, blockHash, SHA256_DIGEST_LENGTH);
}
}
