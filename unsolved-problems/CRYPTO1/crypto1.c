#include <stdio.h>
#include <time.h>

#define RADIX 4000000007LL

/**
*	time_t:
*	This is the data type used to represent calendar time. In the GNU C library and other POSIX-compliant implementations.
* 	time_t is equivalent to long int. When interpreted as an absolute time value, it represents the number of seconds elapsed since 00:00:00 on January 1, 1970, Coordinated Universal Time.
*	(This date is sometimes referred to as the epoch.)
**/

typedef long long int i64_t;

i64_t mod_exp(i64_t base, i64_t exp, i64_t rad);

int main() {
	i64_t cipher, residue;
	time_t epoch_s;
	while(scanf("%lld", &cipher) == 1) {
		//Check if a**((p-1)/2) == 1 MOD p to determine existence of solutions to the quadratice congruence.
		residue = mod_exp(cipher, (RADIX-1LL)/2LL, RADIX);
		if(residue == 1) {
			//Exatly 2 solutions exist
		}
	}
	return 0;
}

/**
*	Implement fast modular exponentiation
**/

i64_t mod_exp(i64_t base, i64_t exp, i64_t rad) {
	i64_t res = 1;
	while(exp>0) {
		if(exp%2 == 1) {
			res = (res*base)%rad;
		}
		exp >>= 1;
		base = (base*base)%rad;
	}
	return res;
}
