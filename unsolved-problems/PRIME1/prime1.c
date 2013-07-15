/**
*	Will try to implement a prime sieve. either Atkins or Eratosthenes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END 1000                            						/* The last number in the computation */

int main() {
	int *sieve;                         							/*	Declare sieve array to contain truth value of isPrime(k)	*/
	sieve = (int *) malloc(END * sizeof(int) );
	memset(sieve, 1, sizeof(sieve));        						/*	Start off with assumption that all numbers are prime	*/

	int base_primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23};      		/*	We assume to know these 10 numbers to be prime, saves factoring effort for first 600 numbers	*/



	return 0;
}
