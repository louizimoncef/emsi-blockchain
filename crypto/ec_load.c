#include "hblk_crypto.h"
EC_KEY *ec_load(char const *folder)
{
char file[512] = { 0 };
FILE *f, *f1;
EC_KEY *ec_key = NULL;
struct stat st;
if (!folder)
return (NULL);
if (stat(folder, &st) == -1)
return (NULL);
sprintf(file, "./%s/%s", folder, PUB_FILENAME);
f = fopen(file, "r");
sprintf(file, "./%s/%s", folder, PRI_FILENAME);
f1 = fopen(file, "r");
if (!f && !f1)
return (NULL);
if (!PEM_read_EC_PUBKEY(f, &ec_key, NULL, NULL))
return (NULL);
fclose(f);
if (!PEM_read_ECPrivateKey(f1, &ec_key, NULL, NULL))
return (NULL);
fclose(f1);
return (ec_key);
}
