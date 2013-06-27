#include<stdio.h>
typedef long long int i64_t;
int main() {
	i64_t a, b, t, m, n, e, a0, d;				/*3rd term, 3rd last term, testcases, sum, element count, index, zeroth term and common difference*/
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld %lld", &a, &b, &m);
		e=0LL;									/*Added LL suffix to avoid any goof casts*/
		
		n = 2LL*(m/(a+b));						/*Calculate no of terms in the progression*/
		d=(b-a)/(n-5LL);						/*Calculate common differnce of progression*/
		a0=a-2LL*d;								/*Calculate first term of progression*/
		
		printf("%lld\n", n);
		
		while(e<n) {
			printf("%lld ", a0+(e++)*d);		/*Trailing whitespace*/
		}
		printf("\n");							/*BORED OF TLE*/
	}
	return 0;
}
