/* Recaman sequence http://oeis.org/A005132 */

#include <stdio.h>

#define SIZE 500001
#define MAXVAL 50000001

int main() {
    int n, i, temp;
	int a[SIZE] = {0};
	int is_present[MAXVAL] = {0};                              /* Hash table for reference */
	for(i = 1; i < SIZE; ++i) {
		temp = a[i - 1] - i;
		if(temp > 0 && is_present[temp] == 0) {
			a[i] = temp;
			is_present[temp] = 1;
		}
		else {
			temp = (a[i] = a[i - 1] + i);
			if(is_present[temp] == 0) {
				is_present[temp] = 1;
			}
		}
	}
	while(1) {
		scanf("%d", &n);
		if(n != -1) {
			printf("%d\n", a[n]);
		}
		else {
			break;
		}
	}
	return 0;
}

