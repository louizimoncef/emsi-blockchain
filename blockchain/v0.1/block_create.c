#include "blockchain.h"


block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len){

	block_t *block;
	uint32_t max_len = BLOCKCHAIN_DATA_MAX;
	
	if(data_len < max_len){
		max_len = data_len;
	}
	

	if (!prev || !data)	return NULL;
	
	block = malloc(sizeof(*block));
	
	if (!block) return NULL;

	block->data.len = max_len;
	memcpy(block->data.buffer, data, max_len);


	memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);

	block->info.index = prev->info.index + 1;

	block->info.timestamp = (uint64_t)time(NULL);

	return block;
}
