#include "hblk_crypto.h"

/**
 * ec_from_pub - create ec key from public key
 * @pub: public key
 * Return: ec key or NULL
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
if (pub)
{
EC_POINT *ecp = NULL;
EC_GROUP *ec_group_new = EC_GROUP_new_by_curve_name(EC_CURVE);
BN_CTX *bnctx = BN_CTX_new();
EC_KEY *ec_key = EC_KEY_new();
if (!ec_group_new)
return (NULL);
ecp = EC_POINT_new(ec_group_new);
if (!ecp)
return (NULL);
if (EC_POINT_oct2point(ec_group_new, ecp, pub, EC_PUB_LEN, bnctx))
{
EC_KEY_set_group(ec_key, ec_group_new);
EC_KEY_set_public_key(ec_key, ecp);
EC_POINT_free(ecp);
EC_GROUP_free(ec_group_new);
BN_CTX_free(bnctx);
return (ec_key);
}
EC_POINT_free(ecp);
EC_GROUP_free(ec_group_new);
BN_CTX_free(bnctx);
EC_KEY_free(ec_key);
}
return (NULL);
}

