#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

void printa(char a[], int dest_type);

int main() {
    int t, size, x;
    int num[MAX];
    scanf("%d", &t);
    while(t>0) {
        char a[MAX];
    	scanf("%s", a);
		size = strlen(a);
		
		//Cast to an int array
		for(x=0; x<size; x++) {
			a[x] -= '0';
			num[x]= (int) a[x];
			//printf("%d", num[x]);	//Check cast
		}
		//printf(",%d, %d\n", x, size);
		
        //Create flag array to handle non-palindromes.
        int flag[size];
        for(x=0; x<size; x++) {
        	//Initialize, because "int flag[size] = {0};" seems to be bad with spoj engine.
			flag[x] = 0;
		}
        for(x=0; x<(size/2); x++) {
            flag[size-x-1] = num[x] - num[size-x-1];
            printf("%d.", flag[size-x-1]);
        }
        
        //Handle normal non-palindrome numbers.
        for(x=size-1; x>(size/2); x--) {
    		num[x] += flag[x];
		}
		
		t--;
        printf("\n");
	}
	return 0;
}

