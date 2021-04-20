#include "blockchain.h"
/**
 *blockchain_destroy - destroy a blockchain
 *@block: the blockchain to be destroy
 */
void blockchain_destroy(blockchain_t *blockchain)
{
if (blockchain){
llist_destroy(blockchain->chain, 1, NULL);
free(blockchain);
}
}
