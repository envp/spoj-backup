/**
*	Will try to implement Atkin's prime sieve.
*   References:
*   A. Theory:
*   1. https://en.wikipedia.org/wiki/Sieve_of_Atkin
*   2. http://mathworld.wolfram.com/QuadraticSieve.html
*   Common debug:
*   1. http://stackoverflow.com/questions/2398894/why-is-my-implementation-of-the-sieve-of-atkin-overlooking-numbers-close-to-the
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <time.h>

typedef enum {
	FALSE,
	TRUE
} boolean;

typedef long long unsigned ui64_t;

#define RANGE_END 1000000000
//#define RANGE_LENGTH 100000
#define PUT_NEWLINE printf("\n")

void write_primes(const char *filename, const char *mode, boolean *sieve, ui64_t sieve_length);
void sieve_init(boolean *sieve, ui64_t sieve_length, boolean data);		/* Initializes sieve with a global FALSE except 2, 3, 5 */
void fill_candidate_primes(boolean *sieve, ui64_t sieve_length);
void sieve_composites(boolean *sieve, ui64_t sieve_length);

int main() {

	int flag;
	ui64_t sieve_length = (ui64_t)sqrtl(RANGE_END) + 1;
	ui64_t m, n, i, j;
	ui64_t x;

	boolean *is_prime = malloc(sieve_length * sizeof(boolean));
	if(is_prime != NULL) {
		int t;
		*(is_prime + 2) = TRUE;                                 /* Set first 2 primes to TRUE, as a starting assumption */
		*(is_prime + 3) = TRUE;
		sieve_init(is_prime, sieve_length, FALSE);
		fill_candidate_primes(is_prime, sieve_length);
	    sieve_composites(is_prime, sieve_length);

	    /* The actual IO */
	    scanf("%d", &t);
	    while(t > 0) {
			scanf("%lld %lld", &m, &n);
			if(n < sieve_length) {
				for(i = m; i < n + 1; ++i) {
					if(*(is_prime + i)) {
						printf("%lld\n", i);
					}
				}
				PUT_NEWLINE;
			}
			else {
				if(m%2 == 0) {
					m += 1;
				}
				for(i = m; i <= n; i += 2) {
					x = sqrtl(i) + 1;
					flag = 0;
					for(j = 2; j <= x; ++j) {
						if(*(is_prime + j) && (i % j == 0) ) {
							flag = 1;
							break;
						}
					}
					if(flag == 0) {
						printf("%d\n", i);
					}
				}
				PUT_NEWLINE;
			}
		t--;
		}
		free(is_prime);
	}
	else {
		/* Just a temporary exit fix for a HUGE segfault */
		printf("Couldn't allocate enough memory, EXITING WITH STATUS 11!");
		exit(11);
	}
	
	return 0;
}


/* Seperated this out into its own method */
inline void write_primes(const char *filename, const char *mode, boolean *sieve, ui64_t sieve_length) {
 	FILE *fileptr = fopen(filename, mode);
 	if(fileptr != NULL) {
	 	ui64_t i, count = 0;
		for(i = 1; i < sieve_length; ++i) {
			if(*(sieve + i)) {
				fprintf(fileptr, "%lld\n", i);
				++count;
			}
		}
//		printf("GENERATED %lld PRIMES\n", count);
		fclose(fileptr);
	}
	else {
		printf("Unable to open file %s for mode %s EXITING WITH STATUS 1", filename, mode);
		exit(1);
	}
}

/* Initialize the sieve with only 2,3 as PRIME */
inline void sieve_init(boolean *sieve, ui64_t sieve_length, boolean data) {
 	int i;
 	for(i = 4; i < sieve_length; ++i) {
		*(sieve + i) = data;
	}
//	printf("INITIALIZED SIEVE!\n");
}

/*
*	Put in candidate primes:
*	integers which have an odd number of representations by certain quadratic forms
*/
inline void fill_candidate_primes(boolean *sieve, ui64_t sieve_length) {
 	ui64_t limit = (ui64_t)sqrt(sieve_length) + 1;
 	ui64_t x, y, n;
	for(x = 1; x < limit; ++x) {
		for(y = 1; y < limit; ++y) {
			n = 4 * x * x + y * y;
			if(n <= sieve_length && (n%12 == 1 || n%12 == 5 )) {
				*(sieve + n) = ! *(sieve + n);
			}
			n = 3 * x * x + y * y;
			if(n <= sieve_length && n%12 ==7) {
				*(sieve + n) = ! *(sieve + n);
			}
			n = (x > y)?(3 * x * x - y * y):(sieve_length + 1);
			if(n <= sieve_length && n%12 == 11) {
				*(sieve + n) = ! *(sieve + n);
			}
		}
	}
//	printf("FILLED CANDIDATES!\n");
}

/* 	Eliminate composites via sieving
*	n is prime, omit multiples of its square;
*	this is sufficient because composites which managed to get
*	on the list cannot be square-free
*/
inline void sieve_composites(boolean *sieve, ui64_t sieve_length) {
 	ui64_t k, i;
 	for(i = 5; i < sieve_length; ++i) {
		if(*(sieve + i)) {
			ui64_t sqr = i * i;
			for(k = sqr; k < sieve_length; k += sqr) {
				*(sieve + k) = FALSE;
			}
		}
	}
//	printf("SIEVED COMPOSITES!\n");
}
