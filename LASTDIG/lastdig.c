/* modular exp took me a lot of time to get my shit together :/ */

#include <stdio.h>

typedef long long int i64_t;
i64_t mod_exp(i64_t base, i64_t exp, i64_t rad);

int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t > 0) {
		scanf("%d %d", &a, &b);
		a %= 10;
		if(b == 0) {
			printf("1\n");
		}
		else{
			if(a == 0 || a == 1 || a == 5 || a ==6) {
				printf("%d\n", a);
			}
			else {
				printf("%lld\n", mod_exp(a, b, 10));
			}
		}
		t--;
	}
	return 0;
}
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
