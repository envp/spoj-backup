#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int low, int high);

int main() {
	int t, *male, *female;
	static int n, maxVal, i;
	scanf("%d", &t);
	while(t--) {
		maxVal = 0;
  		scanf("%d", &n);
		male = malloc(n * sizeof(int));
		female = malloc(n * sizeof(int));
		for(i = 0; i < n; ++i) {
			scanf("%d", (male + i));
		}
		for(i = 0; i < n; ++i) {
			scanf("%d", (female + i));
		}
		quick_sort(male, 0, n - 1);
		quick_sort(female, 0, n - 1);
		for(i = 0; i < n; ++i) {
			maxVal += *(male + i) * (*(female + i));
		}
		printf("%d\n", maxVal);
	}
	return 0;
}

void quick_sort(int *arr, int low, int high) {
	int pivot, j, temp, i;
	if(low < high) {
	 	pivot = low;
	  	i = low;
	  	j = high;
		while(i < j) {
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
