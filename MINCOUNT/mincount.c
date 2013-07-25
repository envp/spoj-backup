/*
*   Minimum number of moves needed to invert a coin triangle with base 'h' is [T(h)/3] where [.] is the floor function
*/

#include <stdio.h>

typedef long long int i64_t;

int main() {
	int t;
	i64_t h, moves;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &h);
		moves = h * (h + 1)/6;
		printf("%lld\n", moves);
	}
	return 0;
}
