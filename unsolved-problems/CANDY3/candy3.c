#include <stdio.h>

typedef long long unsigned ui64_t;

int main() {
    ui64_t i, n, flag, temp;
    int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		flag = 0;
		for(i = 0; i < n; ++i) {
			scanf("%lld", &temp);
			flag += temp;
			flag %= n;
		}
		(flag == 0)?printf("YES\n"):printf("NO\n");
	}
	return 0;
}

