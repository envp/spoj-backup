#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <time.h>

#define RANGE 10000001

typedef enum {
	FALSE,
	TRUE
} boolean;

typedef long long unsigned ui64_t;

inline void sieve_init(boolean *sieve, ui64_t sieve_length, boolean data);
inline void fill_candidate_primes(boolean *sieve, ui64_t sieve_length);
inline void sieve_composites(boolean *sieve, ui64_t sieve_length);
inline void fill_my_sieve(boolean *sieve, ui64_t sieve_length, boolean data);

int main() {
	int j, i, n, t, x;
	ui64_t sieve_length = (ui64_t)sqrtl(RANGE) + 1;
	boolean *is_prime = malloc(sieve_length * sizeof(boolean));
	ui64_t *a = malloc(RANGE * sizeof(ui64_t));
	ui64_t *f = malloc(RANGE * sizeof(ui64_t));
	if(is_prime != NULL && a != NULL && f != NULL) {
		f[0] = (a[0] = 0);
		f[1] = !(a[1] = 0);
		f[4] = (f[2] = 2);
		f[3] = 3;
		fill_my_sieve(is_prime, sieve_length, FALSE);

		for(i = 5; i < RANGE; ++i) {
			if(is_prime[i]) {
				f[i] = i;
			}
			else {
				if(i % 2 == 0) {
					f[i] = 2;
				}
				else {
					x = 1 + (int)floor(sqrt(i));
					for(j = 3; j <= x; j += 2) {
						if(is_prime[j] && i % j == 0) {
							f[i] = j;
						}
					}
				}
			}
		}
		scanf("%d", &t);
		while(t--) {
			scanf("%d", &n);
			printf("%d\n", a[n]);
		}
	}
	free(is_prime);
	free(a);
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

inline void fill_my_sieve(boolean *is_prime, ui64_t sieve_length, boolean data) {
	*(is_prime + 2) = TRUE;                                 /* Set first 2 primes to TRUE, as a starting assumption */
	*(is_prime + 3) = TRUE;
	sieve_init(is_prime, sieve_length, FALSE);
	fill_candidate_primes(is_prime, sieve_length);
    sieve_composites(is_prime, sieve_length);
}
