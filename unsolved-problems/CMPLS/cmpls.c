/* Testing Lagrange interpolant for speed here. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long int i64_t;

int main() {
	int t;
	double s, c;
	int i, j, k;
	double val, temp = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf %lf", &s, &c);
		double *f = malloc( (s + c) * sizeof(double));
		memset(f, 0., (s + c) * sizeof(double));
		for(i = 0; i < s; ++i) {
			scanf("%lf", &f[i]);
		}

		printf("\n");
	}
	return 0;
}
