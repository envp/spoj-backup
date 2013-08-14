#include <stdio.h>

int main() {
    int t;
    double n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf", &n);
        printf("%.11lf\n", 0.5*(1.5 - 1/(n + 1) + 1/(n + 2)));
    }
    return 0;   
}