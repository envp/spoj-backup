#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000000

int isCubeFree(int , int *); 					/* Returns position among cubefree numbers, 0 if number is not cubefree*/

int main() {
	int i, n ,t;
	int cfr, j, k;
	int *sieve = malloc((LIMIT + 1) * sizeof(int));
	memset(sieve, 1, (LIMIT + 1) * sizeof(int));
	sieve[0] = 0;                           		/* Not considered */
	for(i = 2; i <= LIMIT; ++i) {
		k = i*i*i;
		for(j = k; j <= LIMIT; j += k) {     	/* Eliminates multiples of cubes and cubes */
			if( *(sieve + j) != 0 ) {
				*(sieve + j) = 0;
			}
		}
	}
	scanf("%d", &t);
	for(i = 0; i < t; ++i) {
		scanf("%d", &n);
		printf("Case %d: ", i);
		cfr = isCubeFree(n, sieve);
		if(cfr == 0)
			printf("Not Cube Free\n");
		else
			printf("%d\n", cfr);
	}
	free(sieve);
	return 0;
}

int isCubeFree(int n, int *sieve) {
	int i, c = 0;
	if(sieve[n] == 1) {
		for(i = 0; i < n; ++i) {
			c += sieve[i];
		}
		return (c + 1);
	}
	else {
		return 0;
	}
}
