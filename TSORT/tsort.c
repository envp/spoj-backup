#include <stdio.h>

void quick_sort(int *arr, int low, int high);

int main() {
	int i, n;
	scanf("%d", &n);
	int arr[1000001];
	for(i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n - 1);
	for(i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
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
