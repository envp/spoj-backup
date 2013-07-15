#include <stdio.h>

int main() {
	int t, c=1;
	long long int n;
	scanf("%d", &t);
	while(t--) {
 		scanf("%lld", &n);
 		printf("Case %d: %lld\n", c, (n * (n - 1LL) * (n - 2LL))/ 6LL);
 		c++;
 	}
	return 0;
}
