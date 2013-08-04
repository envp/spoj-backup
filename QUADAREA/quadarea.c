#include <stdio.h>
#include <math.h>

int main() {
	int t;
	double a, b, c, d;
	double s, x;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		s = 0.5 * ((a + b) + (c + d));
		x = sqrt((s - a) * (s - b) * (s - c) * (s - d));
		printf("%.2lf\n", x);
	}
	return 0;
}
