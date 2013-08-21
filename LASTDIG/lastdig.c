/* modular exp took me a lot of time to get my shit together :/ */

#include <stdio.h>

typedef long long unsigned i64_t;
i64_t me(i64_t b, i64_t e, i64_t d);

int main(t) {
	i64_t a, b, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%llu %llu", &a, &b);
		a%=10;
		if(!b)
   			r=1;
		else{
			if(a == 0 || a == 1 || a == 5 || a ==6)
				r=a;
			else
				r=me(a, b, 10);
		}
		printf("%llu\n", r);
	}
	return 0;
}
i64_t me(i64_t b, i64_t e, i64_t d) {
	i64_t r = 1;
	while(e>0) {
		if(e&1) {
			r=(r*b)%d;
		}
		e >>= 1;
		b = (b*b)%d;
	}
	return r;
}
