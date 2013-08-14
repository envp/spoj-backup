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

#define RANGE_END 10000
#define LIMIT 101


void sieve_init(boolean *sieve, ui64_t sieve_length, boolean data);
void fill_candidate_primes(boolean *sieve, ui64_t sieve_length);
void sieve_composites(boolean *sieve, ui64_t sieve_length);
ui64_t factors(boolean *sieve, ui64_t sieve_length, int *n);

int main() {
 boolean *is_prime = malloc(LIMIT * sizeof(int));
	int j, i, n, n_factors = 0;
	sieve_init(is_prime, LIMIT, FALSE);
	*(is_prime + 2) = TRUE;
	*(is_prime + 3) = TRUE;
	fill_candidate_primes(is_prime, LIMIT);
	sieve_composites(is_prime, LIMIT);
	scanf("%d", &n);

	printf("%d", n_factors);
	return 0;
}


/* Initialize the sieve with only 2,3 as PRIME */
inline void sieve_init(boolean *sieve, ui64_t sieve_length, boolean data) {
 	int i;
 	for(i = 4; i < sieve_length; ++i) {
		*(sieve + i) = data;
	}
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
}
ui64_t factors(boolean *sieve, ui64_t sieve_length, int *n) {

}
