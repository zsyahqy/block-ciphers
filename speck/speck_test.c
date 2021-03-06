
#include <stdio.h>

#include "speck.h"

void simon_64_96_test () {
	/*
	 * Speck 64/96
	 */
	u8 inputKey[] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13};
	u8 keys[SPECK_BLOCK_SIZE/16*SPECK_ROUNDS_96];
	// plain text: 74614620 736e6165
	u8 plainText[] = {0x65, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74};

	speck_64_96_key_schedule(inputKey, keys);

	printf("PlainText: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);

	speck_64_96_encrypt(plainText, keys);
	// cipher text: 9f7952ec 4175946c
	printf("After encryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);

	speck_64_96_decrypt(plainText, keys);
	printf("After decryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);
}

void simon_64_128_test() {
	/*
	 * Speck 64/128
	 */
	u8 inputKey[] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13, 0x18, 0x19, 0x1a, 0x1b};
	u8 keys[SPECK_BLOCK_SIZE/16*SPECK_ROUNDS_128];
	// plain text: 3b726574 7475432d
	u8 plainText[] = {0x2d, 0x43, 0x75, 0x74, 0x74, 0x65, 0x72, 0x3b};

	speck_64_128_key_schedule(inputKey, keys);

	printf("PlainText: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);

	speck_64_128_encrypt(plainText, keys);
	// cipher text: 8c6fa548 454e028b
	printf("After encryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);

	speck_64_128_decrypt(plainText, keys);
	printf("After decryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
		plainText[0], plainText[1], plainText[2], plainText[3], 
		plainText[4], plainText[5], plainText[6], plainText[7]);
}

int main () {

	simon_64_96_test();

	simon_64_128_test();

	return 0;
}
