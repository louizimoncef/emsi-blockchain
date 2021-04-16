#include "hblk_crypto.h"
EC_KEY *ec_create(void)
{
EC_KEY *ec_key = EC_KEY_new();
EC_GROUP *ec_group_new = EC_GROUP_new_by_curve_name(EC_CURVE);
const EC_GROUP *ec_group = ec_group_new;
if (!EC_KEY_set_group(ec_key, ec_group))
return (NULL);
if (!EC_KEY_generate_key(ec_key))
return (NULL);
EC_GROUP_free(ec_group_new);
return (ec_key);
}
