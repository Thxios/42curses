
#include <ctype.h>
#include <stdio.h>


int main() {
	for (int c = 256; c < 512; c++) {
		printf("%03d : %02x : isascii - %d\n", c, c, isascii(c));
	}
	char a = '0';
	printf("%d\n", (a-48)*64);
}

