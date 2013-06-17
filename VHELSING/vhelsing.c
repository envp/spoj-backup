#include <stdio.h>
#include <math.h>
int main() {
    int i;
    double r;
    scanf("%d",&i);
    while(i) {
        scanf("%lf",&r);
        printf("%.4lf\n", 8*(2-sqrt(2))*r*r*r );
        --i;
    }
    return 0;
}
