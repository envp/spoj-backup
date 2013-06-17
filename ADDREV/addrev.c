/*Adding Reversed Numbers
**Needs a faster way to implement direct addition for reversed numbers, which would be better than the trivial logic implemented in main().
*/
#include <stdio.h>
 
int main() {    //Ze logix.
    int cases, a,b,sum;
    scanf("%d", &cases);
    while(cases>0) {
        scanf("%d %d", &a, &b);
        a=reverse(a);
        b=reverse(b);
        //printf("%d\n", a);
        //printf("%d\n", b);
        sum=a+b;
        sum=reverse(sum);
        printf("%d\n", sum);
        cases--;
    }
    getchar();
    return 0;
}
 
int reverse(int n) {   //Needs more speed?
    int n_r=0;
    while(n!=0) { //Populate with reverse
        n_r=n_r*10+n%10;
        n/=10;
    }
    return n_r;
}
