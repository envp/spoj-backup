#include <stdio.h>
#include <math.h>

int main() {
	int t;
	double r1, r2, r3, inner;
	scanf("%d", &t);
	while(scanf("%lf %lf %lf", &r1, &r2, &r3) == 3) {
		inner = (r1 * r2 * r3)/((r1*(r2 + r3) + r2 * r3)+ 2. * sqrt((r1 * r2 * r3)*(r1 + r2 + r3)));
		printf("%.6lf\n", inner);
	}
	return 0;
}


