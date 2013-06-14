#include <stdio.h>

#define MAX 160

void mul_1(int a[], int b[], int c[]);		//Muliplies N-digit number by a single digit +ve integers.
void mul_N(int a[], int b)					//Multiplies N * M digit +ve integers
void add(int a[], int b[], int c[]);
void reverse(int a[]);

int main() {
	int a[MAX]={0};
	int b[MAX]={0};
	int c[MAX][MAX]={0};
	int i, j, prdt, carry=0;
	a[0]=9, a[1]=2, a[2]=3;
	b[0]=9, b[1]=2, b[2]=3;
	reverse(a);
	reverse(b);
	for(i=MAX-1; i>=0; i--) {
		if(b[i]!='\0') {
			for(j=MAX-1; j>=0; j--) {
				if(a[i]!='\0') {
					prdt = b[i]*a[j]+carry;			//81
					c[MAX-i-1][j] = prdt%10;		//1
					carry = prdt/10;				//8
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
		i=0,j=0;
		while(i<MAX) {
			while(j<MAX) {
				if(c[i][j]!=0)
					printf("%d", c[i][j]);
				++j;
			}
			++i;
		}
		printf("\n");
	}
	return 0;
}
void reverse(int a[]) {
	int i=0;
	int b;
	while(a[i]!='\0') {
		b=a[MAX-i-1];
		a[MAX-i-1]=a[i];
		a[i]=b;
		++i;		
	}
}
void mul_1(int a[], int b[], int c[]) {
	int i,j;
	c = {0};	//Initialize
	for(i=MAX-1; i>=0; i--) {
	if(b[i]!='\0') {
		for(j=MAX-1; j>=0; j--) {
			if(a[i]!='\0') {
				prdt = b[i]*a[j]+carry;			//81
				c[j] = prdt%10;					//1
				carry = prdt/10;				//8
			}
			else {
				break;
			}
		}
	}
	else {
		break;
	}
}
