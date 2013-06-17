#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW_MAX 100 //200/2
#define COL_MAX 20
#define LEN_MAX 200
int main() {
    int cols,rows;
    char cipher[LEN_MAX];
    //char plain[LEN_MAX];
    while(1) {
        scanf("%d",&cols);
        if(cols==0) {
			break;
		}
        else {
			scanf("%200s", cipher);
			int i, j, k=0, len = strlen(cipher);
			while(cipher[i] != '\0') {
				rows = len/cols;
				char plain[len];
				for(i=0; i<cols; i++) {
					for(j=0; j<rows; j++) {
						plain[i*rows+j] = cipher [k];
						k++;
					}
				}
    		}
		}
	}
    return 0;
}
