/** Everybody hates Raymond. HeÅis the largest stamp collector on planet earth and because of that he always makes fun of all the others at the stamp collector parties.
*	Fortunately everybody loves Lucy, and she has a plan. She secretly asks her friends whether they could lend her some stamps,
*	so that she can embarrass Raymond by showing an even larger collection than his.
*	Raymond is so sure about his superiority that he always tells how many stamps heÅfll show,
*	and since Lucy knows how many she owns, she knows how many more she needs.
*	She also knows how many friends would lend her some stamps and how many each would lend.
*	But sheÅlikes to borrow from as few friends as possible and if she needs too many then sheÅfd rather not do it at all.
*	Can you tell her the minimum number of friends she needs to borrow from?
*/

#include <stdio.h>
#include <stdlib.h>

#define _NEWLINE '\n'
#define _WHITESPACE ' '

int count;														/* Maintain global scenario count */

void quick_sort(int *arr, int low, int high);

int main() {
	int t, stamps_needed, n_friends;
	int temp;
	scanf("%d", &t);

	while(t--) {
		++count;
		scanf("%d %d", &stamps_needed, &n_friends);				/* Read no of stamps Gaymond has and no. of friends Lucy has. */
		int *stamps;
		stamps = (int *) malloc(n_friends * sizeof(int));
		int i = 0;												/* Shorter scope? Does it even matter? */
		while(i < n_friends) {
			scanf("%d", &temp);
			if(temp != _WHITESPACE || temp != _NEWLINE) {		/* Read any non-whitespace characters into *stamps array */
//				printf("YAY %d\n", i);							/* I'm paranoid. */
				*(stamps + i) = temp;							/* Won't increment pointer coz lolmagix */
				++i;
			}
		}

		quick_sort(stamps, 0, n_friends - 1);					/* Stolen sort code */
		i = 0;													/* Reset the counter !! */
		while(stamps_needed > 0 && i < n_friends) {
			stamps_needed -= *(stamps + n_friends - 1 - i);		/* Reading array from end because it is sorted ascending <- LOLWTF*/
			++i;
		}
		printf("Scenario #%d:\n", count);						/* Why twice when once is enough? */

		if(stamps_needed <= 0) {								/* deficit does not exist so she's won */
			printf("%d\n\n", i);
		}
		if(stamps_needed > 0) {
			printf("impossible\n\n");							/* IMPOSSIBRU.JPG !!! */
		}
		free(stamps);											/* Free useless memory */
	}
	return 0;
}

																/* Quick sort code stolen from God-knows-where, I'll implement it myself soon. */
																/* Well I did clean it up myself :D */
void quick_sort(int *arr, int low, int high) {
	int pivot, j, temp, i;
	if(low < high) {
	 	pivot = low;
	  	i = low;
	  	j = high;
		while(i<j) {
	   		while( ( *(arr + i) <= *(arr + pivot) ) && ( i < high ) ) {
	    		i++;
	   		}
	   		while( *(arr + j) > *(arr + pivot) ) {
	    		j--;
	   		}
			if(i < j) { 
	    		temp = *(arr + i);
	    		*(arr + i) = *(arr + j);
	    		*(arr + j) = temp;
	   		}
	  	}
	  	temp = *(arr + pivot);
	  	*(arr + pivot) = *(arr + j);
	  	*(arr + j) = temp;
	  	quick_sort(arr, low, j-1);
	  	quick_sort(arr, j+1, high);
	}
}
