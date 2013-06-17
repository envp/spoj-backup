//This is a Hailstone sequence, print something if it finishes, & NIE if it doesnt, well Collatz's Conjecture is good.

#include<stdio.h>

int main() {
    long long int n;
    scanf("%lld",&n);
        if(n == 0)
            printf("TAK\n");
        else if((n & n-1) == 0)
            printf("TAK\n");
        else
            printf("NIE\n");
    return 0;
}
