/*
*	https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind#Parity
*/

#include <stdio.h>

int main() {
	unsigned t, n, m;
	unsigned parity;
	scanf("%u", &t);
	while(t > 0) {
		scanf("%u %u", &n, &m);
		parity = ((n - m) & ((m - 1)/2)) == 0;
		printf("%u\n", parity);
		t--;
	}
	return 0;
}
