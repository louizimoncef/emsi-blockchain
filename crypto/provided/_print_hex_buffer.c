#include "hblk_crypto.h"
void _print_hex_buffer(uint8_t const *buf, size_t len)
{
size_t i;
for (i = 0; i < len; i++)
printf("%02x", buf[i]);
printf("\n");
}

