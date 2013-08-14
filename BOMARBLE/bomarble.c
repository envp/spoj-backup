#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n) == 1 && n != 0) {
		printf("%d\n", 1 + ((3 * n + 5) * n) /2);
	}
	return 0;
}
