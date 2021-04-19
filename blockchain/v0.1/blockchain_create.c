#include "blockchain.h"

/**
 * blockchain_create - create a block chain with genesis
 * Return: a new blockchain structure
 */
blockchain_t *blockchain_create(void)
{
block_t gene = GENESIS_BLOCK, *genesis;
blockchain_t *blockchain;
genesis = (block_t *) malloc(sizeof(block_t));
memcpy(genesis, (block_t *) &gene, sizeof(block_t));
blockchain = (blockchain_t *) malloc(sizeof(blockchain_t));
blockchain->chain = llist_create(MT_SUPPORT_TRUE);
if(blockchain->chain)
{
free(genesis);
free(blockchain);
return (NULL);
}
if (llist_add_node(blockchain->chain, genesis, ADD_NODE_FRONT) == 0)
return (blockchain);
free(blockchain->chain);
free(blockchain);
free(genesis);
return (NULL);
}
