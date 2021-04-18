#include "hblk_crypto.h"


/**
 * ec_verify - Verifies a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 * Return: 1 if sucess, 0 if failure
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t const *sig)
{
if (key  && msg  && sig && sig->len)
if (ECDSA_verify(0, msg, msglen,
(void *)sig->sig, (int)(sig->len), (void *)key))
return (1);
return (0);
}
