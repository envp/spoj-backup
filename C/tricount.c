#include <stdio.h>

int main() {
    int n;
    unsigned long long int l,u,d;
    scanf("%d", &n);
    while(n) {
        scanf("%Ld",&l);
        unsigned long long int k=l/2;
        u=l*(l+1)*(l+2)/6;
        d=(l%2)?(k*(k+1)*(4*k+5)/6):(k*(k+1)*(4*k-1)/6);
        printf("%Ld\n",u+d);
        --n;
    }
    return 0;
}
