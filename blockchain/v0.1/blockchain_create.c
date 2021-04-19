#include "blockchain.h"


blockchain_t *blockchain_create(void){
	blockchain_t *blockchain;
	block_t *genesis;

	blockchain = malloc(sizeof(*blockchain));


	if (blockchain == NULL) return NULL;

	/* Creating genesis block  with prefixed values */

	char data[] =  "Holberton School";
	char hash[] = "c52c26c8b5461639635d8edf2a97d48d0c8e0009c817f2b1d3d7ff2f04515803";
	uint8_t len = strlen(data);
	int _timestamp =	1537578000;
	

	genesis = (block_t*)malloc(sizeof(*genesis));

	if (genesis == NULL) return NULL;

	memcpy(genesis->data.buffer, data, len);
	genesis->data.len = len;
	// genesis->data.buffer[len] = '\0'
	*(genesis->data.buffer + len) = '\0';

	memcpy(genesis->hash, hash, SHA256_DIGEST_LENGTH);
	genesis->info.timestamp = _timestamp;



	if (genesis == NULL){

		free(blockchain);
		return NULL;
	}


	blockchain->chain = llist_create(MT_SUPPORT_TRUE);

	if (blockchain->chain == NULL){
		free(blockchain);
		free(genesis);
		return NULL;
	}

	if (llist_add_node(blockchain->chain, genesis, ADD_NODE_FRONT) == -1){

		llist_destroy(blockchain->chain, 1, NULL);

		free(blockchain);
		free(genesis);
		return NULL;
	}
	return blockchain;
}
