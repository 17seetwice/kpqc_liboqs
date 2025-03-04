// SPDX-License-Identifier: MIT

#include <stdlib.h>

#include <oqs/kem_smaug_t.h>

#if defined(OQS_ENABLE_KEM_SMAUG_T_3)

OQS_KEM *OQS_KEM_smaug_t_3_new(void) {

	OQS_KEM *kem = OQS_MEM_malloc(sizeof(OQS_KEM));
	if (kem == NULL) {
		return NULL;
	}
	kem->method_name = OQS_KEM_alg_smaug_t_3;
	kem->alg_version = "https://kpqc.cryptolab.co.kr/smaug-t";

	kem->claimed_nist_level = 3;
	kem->ind_cca = true;

	kem->length_public_key = OQS_KEM_smaug_t_3_length_public_key;
	kem->length_secret_key = OQS_KEM_smaug_t_3_length_secret_key;
	kem->length_ciphertext = OQS_KEM_smaug_t_3_length_ciphertext;
	kem->length_shared_secret = OQS_KEM_smaug_t_3_length_shared_secret;

	kem->keypair = OQS_KEM_smaug_t_3_keypair;
	kem->encaps = OQS_KEM_smaug_t_3_encaps;
	kem->decaps = OQS_KEM_smaug_t_3_decaps;

	return kem;
}

extern int kpqc_smaug_t_3_keypair(uint8_t *pk, uint8_t *sk);
extern int kpqc_smaug_t_3_ref_enc(uint8_t *ct, uint8_t *ss, const uint8_t *pk);
extern int kpqc_smaug_t_3_ref_dec(uint8_t *ss, const uint8_t *ct, const uint8_t *sk);

OQS_API OQS_STATUS OQS_KEM_smaug_t_3_keypair(uint8_t *public_key, uint8_t *secret_key) {
	return (OQS_STATUS) kpqc_smaug_t_3_keypair(public_key, secret_key);
}

OQS_API OQS_STATUS OQS_KEM_smaug_t_3_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key) {
	return (OQS_STATUS) kpqc_smaug_t_3_enc(ciphertext, shared_secret, public_key);
}

OQS_API OQS_STATUS OQS_KEM_smaug_t_3_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key) {
	return (OQS_STATUS) kpqc_smaug_t_3_dec(shared_secret, ciphertext, secret_key);
}

#endif
