#include <stdio.h>

typedef long long unsigned ui64_t;

int main() {
	ui64_t N, num = 0, res, inp;
	scanf("%lld",&N);
	int i = 0 ;
	for(; i < N ; i++) {
		scanf("%lld",&inp);
		num ^= inp;
	}
	printf("%lld\n",num);
	return 0;
}
