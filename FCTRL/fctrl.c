//Copute Z(N) the larget power of 10 that N! is divisible by.
#include <stdio.h>

int main() {
	int cases;
	int z;
	int n;
	scanf("%d",&cases);
	while(cases>0) {
 				  scanf("%d",&n);
				  z=zeroes(n);
				  printf("%d\n",z);
				  cases--;
	}
	return 0;
}

int zeroes(int n) {
	int z=0;
	int f=n;
	while(f>0){
		f/=5;
		z+=f;
	}
	return z;
}
