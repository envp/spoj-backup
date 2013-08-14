#include <stdio.h>
int main() {
	long long int a, b, c, x;
	scanf("%lld %lld %lld", &a, &b, &c);
	scanf("%lld", &x);
	printf("%lld\n", ((a*x + b)*x + c));
	return 0;
}
