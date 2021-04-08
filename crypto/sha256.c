#include "hblk_crypto.h"

uint8_t* sha256(int8_t const* s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
   
    if (s) {
        EVP_MD_CTX* mdctx;
        const EVP_MD* md;
        int md_len;
        md = EVP_sha256();
        mdctx = EVP_MD_CTX_create();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, s, strlen(s));
        EVP_DigestFinal_ex(mdctx, digest, &md_len);
        EVP_MD_CTX_destroy(mdctx);
        EVP_cleanup();
    }
  

    return digest ? digest : NULL;
}
