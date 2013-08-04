#include <stdio.h>
#include <math.h>

#define MAX_INPUT_LENGTH 14

typedef long long unsigned ui64_t;

ui64_t reader();

int main() {
    int t, i = 0, n, k, j;
    char temp[MAX_INPUT_LENGTH];
    int num[n];
    static int max_perms, unique;
    int x, head;
    scanf("%d", &t);
    while(t > 0) {
    	x = 0;
    	++i;
    	unique = 0;
    	max_perms = 0;
		printf("Experiment #%d:\n", i);
		scanf("%d %d", &n, &k);
		max_perms = (int)pow(2, n);
		scanf("%s", temp);
		while(x < n) {
			num[x] = (temp [x] == '+') ? 1 : 0;
			++x;
		}
//		for(x = 0; x < n; ++x) {
//			printf("%d", num[x]);
//		}
//		printf("\n");
		for(x = 0; x < max_perms; ++x) {
			num[n - 1] = (num[0] == 1) ? !num[n - 1] : num[n - 1];
			head = 1^num[0];
			for(j = 0; j < n - 1; ++j) {
				num[j] = num[j + 1];
			}
			num[n - 1] = head;

			printf("\n");
		}
		t--;
	}
    return 0;
}
