#include "hblk_crypto.h"
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
int ec_save(EC_KEY *key, char const *folder)
{
char PRK_FN[] = "/key.pem", PUK_FN[] = "/key_pub.pem",
*PRK_dest = NULL, *PUK_dest = NULL;
int const PRK_DEST_LEN = strlen(PRK_FN) + strlen(folder) + 1,
PUK_DEST_LEN = strlen(PUK_FN) + strlen(folder) + 1;
FILE *PRK_F = NULL, *PUK_F = NULL;
PUK_dest = (char *) malloc(PUK_DEST_LEN);
PRK_dest = (char *) malloc(PRK_DEST_LEN);
struct stat st;
if (!key)
return (0);
if (stat(folder, &st) == -1)
{
	if (mkdir(folder, 0700) == -1)
		return 0;
}
if (!PUK_dest && !PRK_dest)
{
	printf("malloc error");
	return (0);
}
PRK_F = fopen(PRK_dest, "w+");
PUK_F = fopen(PUK_dest, "w+");
if (PEM_write_ECPrivateKey(PRK_F, key, NULL, NULL, 0, NULL, NULL) && PEM_write_EC_PUBKEY(PUK_F, key) )
{
fclose(PRK_F);
fclose(PUK_F);
return (1);
}
printf("creating error");
return (0);
	
}
