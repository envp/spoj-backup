/**
*   Majid is a 3rd-grade elementary student and quite well in mathematics.
*	Once, Majid's teacher asked him to calculate the sum of numbers 1 through n.
*	Majid quickly answered, and his teacher made him another challenge.
*	He asked Majid to calculate the sum of the digits of numbers 1 through n.
*/


#include <stdio.h>

#define BASE 10                                                                 /*	Makes for more verbose code, and some redundant typing to test my speed :D LOLWTF	*/
#define UNITS(X) = X % BASE                                                     /*	Will need unit positioned numeral for calculations	*/

typedef long long int i64_t;                                                    /*	9log2(10) ~ 9/0.3010 < 9/0.3 = 30	*/

inline i64_t sumOfDigits(i64_t x);
inline int power(int b, int e);

int main() {
	
	int t;
	i64_t a, b;
	
	/*	scanf returns number of parameters successfully read from stdin	*/
	while( scanf("%lld %lld", &a, &b) == 2 &&  a != -1 && b != -1 ) {
		i64_t low, high;
		low = sumOfDigits(a);
		high = sumOfDigits(b);
		printf("%lld\n", high - low);
	}
	return 0;
}
inline i64_t sumOfDigits(i64_t x) {
	/*	Set up a LUT for partial sums i.e. triangular numbers, oeis/A000217	*/
	int trinum[10] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45 };

	i64_t q = 1, r, sum = 0;
	int a = x, i = 0;
	int p;

	/*	Loop handles everything except the correction for the incomplete part of the sum, ofcourse	*/
	while(a > 0) {
		r = a % BASE;
		q = a / BASE;
		sum += power(10, i) * (trinum[r] + q * trinum[9]);
		a /= BASE;
		++i;
	}

	/*	Handle the incomplete part of the number i.e for 473 we have to handle the sum of digits (except units) for 470...473 => (4 + 7) * (3 + 1)	*/
	i = 0;
	a = x;
	/*while( (p = a%BASE) >0) {
		sum += (i>0)?( x%BASE * p):0;
		a /= BASE;
		++i;
	}*/
	return sum;
}
inline int power(int b, int e) {
	int res;
	/*	Fix base cases first and then use logic	*/
	if( ( b == 0 || b == 1 ) && e != 0 ) {
		return b;
	}
	/*	Make assumption that 0**0 = 1, although invalid but is a necessary evil	*/
	else if(e == 0) {
		return 1;
	}
	/*	Main logic here, i.e. exponentiaion by squaring	*/
	else if(e == 1) {
		return b;
	}
	else {
		while(e>0) {
			if( e%2 == 0) {
				return power(b*b, e/2);
			}
			else {
				return b * power(b*b, (e - 1)/2);
			}
		}
	}
}
