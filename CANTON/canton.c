#include <stdio.h>
#include <math.h>
//#include <time.h>
//Vector to scalar map
/**
 *	>Initial issues caused by typecasting to int resolved by correct usage of ceil.
 *	>mfw
 */

int main() {
	int n, t, u, z, d;
	scanf("%d", &t);
	while(t>0) {
		scanf("%d", &z);
		//Finding Diagnol
		n = ceil((sqrt(8*z + 1) - 1)/2);
		//Startpoint for diagnol 'n'
   		u = n*(n+1)/2;
   		//Difference required to be processed
   		d = u - z;
		//calc num & den = n - d, 1 + d
		printf("TERM %d IS ", z);
		if(n%2) //Check if odd
			printf("%d/%d\n", 1+d, n-d);
		else
			printf("%d/%d\n", n-d, 1+d);
		t--;
	}
	return 0;
}

