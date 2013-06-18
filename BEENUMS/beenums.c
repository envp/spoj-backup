#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n) == 1 && n!= -1) {
		int u = 1;
		if(n==1)
			printf("Y\n");
		else {
			int i=0;
			while(u<n) {
				u+=6*i;
				i++;
			}
			if(u == n) {
				printf("Y\n");
			}
			else printf("N\n");
		}
	}
	return 0;
}
