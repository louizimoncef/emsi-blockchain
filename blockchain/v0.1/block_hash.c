#include "blockchain.h"

uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH]){

	size_t length = block->data.len + sizeof(block->info);

	return sha256((int8_t const *)block, length, hash_buf);
}
