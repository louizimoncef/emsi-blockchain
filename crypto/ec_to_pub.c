#include "hblk_crypto.h"

/**
 * ec_to_pub - convert ec key to public key
 * @key: pointer to ec key
 * @pub: where we stock public key
 * Return: public key or NULL
 */

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
const EC_GROUP *group;
const EC_POINT *point;
if (!key || !pub)
return (NULL);
group = EC_KEY_get0_group(key);
if (!group)
return (NULL);
point = EC_KEY_get0_public_key(key);
if (!point)
return (NULL);
if (!EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED,
pub, EC_PUB_LEN, NULL))
return (NULL);
return (pub);
}

