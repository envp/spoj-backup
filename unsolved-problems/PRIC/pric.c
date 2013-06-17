#include <stdio.h>

#define RADIX 2147483648
#define MAX_ITER 5

int isPrime(int a);
int Jacobi(int a, int p);

main() {
	int a=1, n=0;
	while(n<MAX_ITER) {
		a=a=(a+1234567890)%RADIX;
		if(a<0) {
			a=-a;
		}
		//printf("%d\n",isPrime(a));
		
		n++;
	}
	return 0;
}}
