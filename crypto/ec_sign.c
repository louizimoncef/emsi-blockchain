/*#include "hblk_crypto.h"
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
*/
#include "hblk_crypto.h"

uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
				 size_t msglen, sig_t *sig)
{
	uint32_t len = 0;

	if (!key || !msg || !msglen)
		return NULL;

	memset(sig->sig, 0, sizeof(sig->sig));
	if (!ECDSA_sign(0, msg, (int)msglen, sig->sig, &len, (EC_KEY *)key))
	{
		sig->len = 0;
		return NULL;
	}
	sig->len = (uint8_t)len;
	return sig->sig;
}
