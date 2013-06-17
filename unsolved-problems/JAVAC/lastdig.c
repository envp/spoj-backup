#include <stdio.h>
#include <math.h>
int main() {
    int t, a, b, b2, b4, s, p;
    scanf("%d", &t);
    typedef double d;
    while(t--) {
    scanf("%d %d", &a, &b);
        a %= 10;
        b2 = (b>2)?b%2:b;
        b4 = (b>4)?b%4:b;
        s = ((int)(pow((d)a, (d)(b2))))%10;
        p = ((int)(pow((d)a, (d)(b4))))%10;
		if(b == 0)      {
            printf("1\n");
		} else {
        	if(a==0||a==1||a==5||a==6)
            	printf("%d\n", a);
        	else if(a==4||a==9)
				printf("%d\n", s);
        	else
				printf("%d\n", p);
        }
    }
    return 0;
}
