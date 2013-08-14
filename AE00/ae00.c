#include <stdio.h>

int main () {
	int n, i, j;
	long long int n_factors;
    scanf("%d", &n);
    n_factors = 0;
    for(i=1;i<=n;i++) {
    	for (j=1;j*j<=i;++j) {
      		if (i%j == 0) {
			  ++n_factors;
			}
  		}
    }
	printf("%lld", n_factors);
return 0;
}
