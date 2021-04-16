#include "hblk_crypto.h"
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
const EC_POINT *ecp=EC_KEY_get0_public_key(key);
const EC_GROUP* ec_group_new = EC_KEY_get0_group(key);
BN_CTX* bnctx = BN_CTX_new();
if (ecp == NULL)
return NULL;

if (ec_group_new==NULL)
{
EC_POINT_free(ecp);
return NULL;
}
if (bnctx == NULL)
{
EC_POINT_free(ecp);
EC_GROUP_free(ec_group_new);
return NULL;
}
int test = EC_POINT_point2oct(ec_group_new, ecp, POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, bnctx);
EC_POINT_free(ecp);
EC_GROUP_free(ec_group_new);
BN_CTX_free(bnctx);
return test?pub:NULL;
}
