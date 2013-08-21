#include <stdio.h>
#include <string.h>

#define MAX 1000

long a[MAX], l;

void a_div_5() {
   int i, carry;

   carry = 0;
   for (i = 0; i < l; i++) {
      a[i] = a[i]*2+carry;
      carry = a[i]/10;
      a[i] = a[i]%10;
   }
   if (carry>0) a[l++] = carry;
   l--;
   for (i=0; i<l; i++) a[i] = a[i+1];
}

int main() {
	/* Input buffer */
	char buff[MAX];
	
	/* Last digits of 0! - 19! modulo 5 */	
	long mod[20]={1, 1, 2, 1, 4, 2, 2, 4, 2, 3, 4, 4, 3, 4, 1, 3, 3, 1, 3, 2};				
	int result, n, i, carry, j, one, zero;
	FILE *in, *out;
	
	/* Input streams assigned */
	in = fopen("in.txt", "r");			
	out = fopen("out.txt", "w");
	
	/* Seems fprintf, fscanf are faster and safer (stackoverflow!) for HUGE streams */
	while ( fscanf(in, "%s", buff) != EOF) {
		l = strlen(buff);
		for (i = 0; i < l; i++) {
			a[i] = buff[l-1-i] - '0';
		}
		
		zero = (l == 1) && (a[0] == 0);
		one = (l == 1) && (a[0] == 1);
		result = 1;

		while (l > 0) {
	   		if (l == 1) {
				result = result * mod[a[0]] % 5;
			}
	   		else {
			   	result = result * mod[a[0] + 10 * (a[1] % 2)] % 5;
			}
			a_div_5();
	   		
		}
		if (zero || one || result % 2 == 0) {
			fprintf(out, "%d\n", result);
		}
		else {
			fprintf(out, "%d\n", result + 5);
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}

/* 
*	Number theory involved:
*	Write N!= (5k + r)! (Exclude any multiples of 5)
*			= (1.2.3.4).5.(6.7.8.9).10.(11.12.13.14).15(16.17.18.19).20.(21.22.23.24)...		(1)
*	This gives the following last non-zero digit pattern:
*			= 1,(1,2,6,4),2,(2,4,2,8),8,(8,6,8,2),8,(8,6,8,2),4,(8,8,4,6)...					(2)
*	A little bit of number theory magic on (1) gives:
*	N! = (5n!) = (5^n) * (n!) * product[k in 0..n-1]((5k+1)(5k+2)(5k+3)(5k+4))
*/
