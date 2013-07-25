/**
*   Hubulullu is an Impartial game where each player starts by picking a number and all of its divisors out of [1...N]
*   The moves are chosen optimally.
*   OPTIMAL MOVE : Each move is made to guarantee victory.
*/

#include <stdio.h>

int main() {
	int t, start;
	long long int n;
	scanf("%d", &t);
	while(t>0) {
		scanf("%lld %d", &n, &start);
		if(start == 0) {
			printf("Airborne wins.\n");
		}
		else {
			printf("Pagfloyd wins.\n");
		}
		t--;
	}
}
