#include "hblk_crypto.h"

int ec_save(EC_KEY *key, char const *folder)
{
FILE *PRK_F=NULL, *PUK_F=NULL;
char PRK_dest[600], PUK_dest[600];
struct stat st;
if (!key || !folder)
return (0);
if (stat(folder, &st) == -1)
{
	if (mkdir(folder, 0700) == -1)
		return 0;
}
sprintf(PRK_dest, "%s/%s", folder, PRK_FN);
sprintf(PUK_dest, "%s/%s", folder, PUK_FN);
PRK_F = fopen(PRK_dest, "w");
PUK_F = fopen(PUK_dest, "w");
if(!PUK_F&&PRK_F)
return (0);
	if (!PEM_write_ECPrivateKey(f, key, NULL, NULL, 0, NULL, NULL))
		return 0;

PEM_write_EC_PUBKEY(PUK_F, key);
fclose(PRK_F);
fclose(PUK_F);
return (1);

return (0);
	
}
