#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

int main() {
	double smaller_radius, n_circles;   					/* Runtime typecasting is a speedkiller*/
	double outer_radius;                                    /* Exocircle radius */
	double scale;                                           /* Stores sine because I want to */
	while(1) {
		scanf("%lf %lf", &smaller_radius, &n_circles);
		if(smaller_radius == 0. && n_circles == 0.) {
			break;
		}
		else {
			scale = sin(PI/(2. * n_circles));              	/* No. of sides is twice teh no of circles */
			outer_radius = smaller_radius / scale;
		}
		printf("%.2lf\n", outer_radius);
	}
	return 0;
}
