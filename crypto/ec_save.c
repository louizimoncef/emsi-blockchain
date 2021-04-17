#include "hblk_crypto.h"
/**
 * ec_save - save ec private aand public keys in PEM files
 * @key: EC_key
 * @folder: destination folder
 * Return: 1 succes 0 failed
 */
int ec_save(EC_KEY *key, char const *folder)
{
char file[512];
FILE *myfile;
struct stat st;

if (!key || !folder)
return (0);
if (stat(folder, &st) == -1)
{
if (mkdir(folder, 0700) == -1)
return (0);
}
sprintf(file, "%s/%s", folder, PRI_FILENAME);
myfile = fopen(file, "w");
if (!myfile)
return (0);
if (!PEM_write_ECPrivateKey(myfile, key, NULL, NULL, 0, NULL, NULL))
return (0);
fclose(myfile);
sprintf(file, "%s/%s", folder, PUB_FILENAME);
myfile = fopen(file, "w");
if (!myfile)
return (0);
if (!PEM_write_EC_PUBKEY(myfile, key))
return (0);
fclose(myfile);
return (1);
}
