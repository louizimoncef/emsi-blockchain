#include "blockchain.h"




int blockchain_serialize(blockchain_t const *blockchain, char const *path) 
{
uint8_t hblk_magic[4];
uint8_t hblk_version[3];
uint8_t hblk_endian;
int32_t hblk_blocks;
FILE *fptr = fopen(path, "w");
if (!fptr)
return (-1);
if (blockchain && path)
{
hblk_blocks = llist_size(blockchain->chain);
if (hblk_blocks == -1) 
return (-1);
memcpy(hblk_magic, "HBLK", 4);
memcpy(hblk_version, "0.1", 3);
hblk_endian = _get_endianness();
fwrite(&hblk_magic, sizeof(hblk_magic), 1, fptr);
fwrite(&hblk_version, sizeof(hblk_version), 1, fptr);
fwrite(&hblk_endian, sizeof(hblk_endian), 1, fptr);
fwrite(&hblk_blocks, sizeof(hblk_blocks), 1, fptr);
if (llist_for_each(blockchain->chain, block_to_file, fptr))
{
fclose(fptr);
return 0;
}
}
fclose(fptr);
return -1;
}
