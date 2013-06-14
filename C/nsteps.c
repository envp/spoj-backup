/*We traverse the points, (0,0)->(1,1)->(2,0)->(3,1)->(2,2)->(3,3)->(4,2) &c, Each of these is labelled serially.
*The code computes the said serial given the point, or prints an appropriate error when an invalid coordinate is entered.
*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    while(n) {
        int x,y;
        scanf("%d %d", &x, &y);
        if(x-y==0 || x-y==2) {
            //int v=x+y - (int)(x%2 || y%2); 
            int v=x+y-(x%2+y%2-(x%2)*(y%2)));   //Yes, I just made that up. Problemo Mucho?
            printf("%d\n",v);
        }
        else {
            printf("No Number\n");
        }
        --n;
    }
    
    return 0;
}
