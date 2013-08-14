#include <stdio.h>

#define PI 3.141592653589

int main() {
    double b, l, v;
    while(1) {
        scanf("%lf %lf", &b, &l);
        if (b != 0 && l != 0) {
			if(l == b) {
				v = b * b * b * (1 - 1/PI) / (4 * PI);
			}
			else {
				
			}	
        }
        else {
            break;
        }
    	printf("%.3lf\n", v);
    }
    return 0;
}