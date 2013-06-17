#include <stdio.h>

#define MAX 160

void reverse(int a[]);
void mul(int a, int b[]);

int main() {
	int t,n, temp;
	int fctrl[MAX] = {0};	//Zero padded array.
	fctrl[0]=1;
	reverse(fctrl);
	scanf("%d", &t);
	while(t>0) {
		
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

void mul(int a, int b[]) {
	printf("MUL %d\n", a);
	int carry = 0, tmp = 1, i=MAX-1;
	while(b[i]!='\0' && tmp>0) {
		printf("MULOOP %d\n", a);
		tmp = ((int)b[i])*a + carry;
		carry = tmp/10;
		b[i] = tmp%10;
		i--;
	}
//	while(tmp%10) {
//		printf("hax %d\n", tmp);
//		b[i+1] = tmp%10;
//		tmp /= 10;
//		i--;
//	}
}
