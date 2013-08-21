#include <stdio.h>

int main() {
	int t, n;
	/* LUT for the last 2 digits of n! */
	int d[] = {1, 1, 2, 6, 24, 20, 20, 40, 20, 80};
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n < 10) {
			printf("%d %d\n", d[n]/10, d[n]%10);
		}
		else {
			printf("0 0\n");
		}
	}
}
