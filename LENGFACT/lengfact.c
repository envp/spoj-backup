#include <stdio.h>
#include <math.h>

#define LOG10_2PI 0.79817986835

typedef long long int lint_t;

int main() {
	lint_t t, n, digits;
	scanf("%lld", &t);
	
	while(t>0) {		
		scanf("%lld", &n);
		double mag, x = log10(n);
		if(n == 0 || n == 1) {
			printf("1\n");
		}
		else {
			mag = n * (x - M_LOG10E) + 0.5 * LOG10_2PI + 0.5 * x;
			printf("%lld\n", 1LL + (lint_t)mag);
		}
		t -= 1LL;
	}
	return 0;
}
