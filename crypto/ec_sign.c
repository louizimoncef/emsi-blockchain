#include "hblk_crypto.h"

/**
 * ec_sign - Signs a given set of bytes, using a given EC_KEY
 * @key: EC key pair
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to  the signature
 * Return: pointer to the signature on sucess NULL failure
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t *sig)
{
memset(sig->sig, 0, sizeof(sig->sig));
if (key && msg)
if (ECDSA_sign(0, msg, msglen, sig->sig,
(unsigned int *) &sig->len, (EC_KEY *) key))
return (sig->sig);
return (NULL);
}
