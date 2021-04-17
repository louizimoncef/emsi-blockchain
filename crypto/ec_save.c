#include "hblk_crypto.h"


int ec_save(EC_KEY *key, char const *folder)
{
	
	FILE file*;
	char dest_ad[512];
	struct stat st;

	if (!key || !folder)
		return 0;
	if (stat(folder, &st) == -1)
	{
		if (mkdir(folder, 0700) == -1)
			return 0;
	}
	sprintf( dest_ad, "%s/%s", folder, PRI_FILENAME);
	file = fopen(dest_ad, "w");
	if (!file)
		return 0;
	if (!PEM_write_ECPrivateKey(file, key, NULL, NULL, 0, NULL, NULL))
		return 0;
	fclose(file);
	sprintf( dest_ad, "%s/%s", folder, PUB_FILENAME);
	file = fopen(dest_ad, "w");
	if (!file)
		return 0;
	if (!PEM_write_EC_PUBKEY(file, key))
		return 0;
	fclose(file);
	return 1;
}
