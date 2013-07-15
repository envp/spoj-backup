#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000                                      /* Will document this shit */

int main() {
	int *a, n, q, opcode, index_1, index_2, i=0, mul3;      /* Orwell Dev-Cpp seems to have some issue with typing *a with the * first (inside loops?) Crashes without even a compile request*/
	scanf("%d %d", &n, &q);                                 /* Formatted input, find a general method? */
	a = (int *)malloc( n * sizeof(int));                    /* Allocate memory for dynamic array a */
	while(i<n) {
		a[i] = 0;
		i++;
		printf("%d", a[i]);
	}
	while(q--) {
		i=0;
		scanf("%d %d %d", &opcode, &index_1, &index_2);     /* Formatted input, find a general method? */
		if(opcode == 0) {
			while(index_1 < index_2 + 1) {
				(*(a+ index_1))++;                      	/* Increment appropriate offset */
				index_1++;
			}
		if(opcode == 1) {
			mul3 = 0;                                       /* Set count of 3-multiples to 0 */
			while(index_1 < index_2 + 1) {
				if((*(a+index_1 + i)) % 3 == 0) {           /* Check! */
					mul3++;
					index_1++;                            	/* Increment 3-multiple counter & offset counter*/
				}
			}
			printf("%d\n", mul3);
		}
		}
	}
	return 0;
}
