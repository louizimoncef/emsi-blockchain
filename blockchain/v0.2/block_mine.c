#include "blockchain.h"
/**
 * block_mine - mining by changing the nonce
 * @block: the mined block
 */
void block_mine(block_t *block)
{
uint8_t blockHash[SHA256_DIGEST_LENGTH];
block_hash(block, blockHash);
block->info.difficulty = 20;
if (!hash_matches_difficulty(blockHash, block->info.difficulty))
{
block->info.nonce = 0;
while (!hash_matches_difficulty(blockHash, block->info.difficulty))
{
block->info.nonce++;
block_hash(block, blockHash);
}
memcpy(block->hash, blockHash, SHA256_DIGEST_LENGTH);
}
}
