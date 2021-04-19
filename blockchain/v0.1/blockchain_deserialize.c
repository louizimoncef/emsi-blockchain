#include "blockchain.h"


void convert_endianness(block_t *block){

	_swap_endian(&block->info.index, sizeof(block->info.index));
	_swap_endian(&block->info.difficulty, sizeof(block->info.difficulty));
	_swap_endian(&block->info.timestamp, sizeof(block->info.timestamp));
	_swap_endian(&block->info.nonce, sizeof(block->info.nonce));
}


int read_blocks(FILE *fp, uint8_t swap_endian, blockchain_t *blockchain, int size){

	int i;
	block_t *block;
	uint32_t data_len;
	long int genesis_size;

	genesis_size = sizeof(block->info) + sizeof(block->hash) + 20L;
	fseek(fp, genesis_size, SEEK_CUR);

	for (i = 0; i < size - 1; ++i){

		block = malloc(sizeof(*block));

		if (!block) return -1;

		fread(&block->info, sizeof(block->info), 1, fp);
		fread(&data_len, sizeof(data_len), 1, fp);

		if (swap_endian)
			_swap_endian(&data_len, sizeof(data_len));

		fread(&block->data.buffer, data_len, 1, fp);
		fread(&block->hash, SHA256_DIGEST_LENGTH, 1, fp);

		if (swap_endian)
			convert_endianness(block);

		block->data.len = data_len;
		*(block->data.buffer + data_len) = '\0';
		llist_add_node(blockchain->chain, block, ADD_NODE_REAR);
	}

	return 0;
}



blockchain_t *blockchain_deserialize(char const *path){

	FILE *fp;
	hblk_file_t header;
	blockchain_t *blockchain;
	int size;
	uint8_t swap_endian;

	if (!path) return NULL;

	if (access(path, R_OK) == -1) return NULL;

	fp = fopen(path, "r");

	if (!fp) return NULL;

	fread(&header, sizeof(header), 1, fp);

	if (memcmp(header.hblk_magic, "HBLK", 4) || memcmp(header.hblk_version, "0.1", 3)){

		fclose(fp)

		return NULL;
	}
		

	blockchain = blockchain_create();

	if (!blockchain){ 
		fclose(fp)
		return NULL;
	}

	swap_endian = _get_endianness() != header.hblk_endian;
	size = header.hblk_blocks;

	if (swap_endian)
		_swap_endian(&size, sizeof(size));
	if (read_blocks(fp, swap_endian, blockchain, size) == -1)
		return (blockchain_destroy(blockchain), fclose(fp), NULL);

	fclose(fp);

	return blockchain;
}
