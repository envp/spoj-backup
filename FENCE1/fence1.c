#include <stdio.h>

#define PI 3.14159526
#define N_IN 1

int main() {
	int l;
	while( (scanf("%d", &l) == N_IN) && (l != 0) ) {
		double x = (double) l;
		double area = x*x*0.5/PI;
		printf("%0.2lf\n", area);
	}
	return 0;
}
