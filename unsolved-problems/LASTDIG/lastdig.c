#include <stdio.h>
#include <math.h>
int main() {
    int t, a, b, b2, b4, s, p;
    scanf("%d", &t);
    typedef double d;
    while(t--) {
    scanf("%d %d", &a, &b);
        a = (a>10)?a%10:a;
        b2 = (b>2)?b%2:b;
        b4 = (b>4)?b%4:b;
        s = (int)floor((pow((d)a, (d)(b2))))%10;
        p = (int)floor((pow((d)a, (d)(b4))))%10;
		if(b == 0)      {
            printf("1\n");
		} else {
        	if(a==0||a==1||a==5||a==6)
            	printf("%d\n", a);
        	else if(a==4||a==9)
				printf("%1d\n", s);
        	else
				printf("%1d\n", p);
        }
    }
    return 0;
}

