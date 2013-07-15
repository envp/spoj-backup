#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SET_SIZE 26
#define BUFSIZE 128
#define INFILE "john_jones_crypto.txt"

typedef unsigned long int uint64_t;

int main() {
	FILE *crypto;
	int freq[SET_SIZE], index, i=0;
	char *line, c;
	line = (char *)malloc(BUFSIZE*sizeof(char));
	crypto = fopen(INFILE, "r");
	fclose(crypto);
	return 0;
}
