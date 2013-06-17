#include <stdio.h>

int main() {
	int t, p=1, n=20;
	char c[20];
	scanf("%d",&t);
	while(--t) {
		scanf("%s", &c);
		while(n--) {
			if(c[n]=='K' || c[n]=='D' || c[n]=='G' || c[n]=='L' || c[n]=='F') {p=p*2;}
			else if(c[n]=='R') {p=p*4;}
			else {p*=1;}
			printf("%d",p);
		}
	}
	return 0;
}
