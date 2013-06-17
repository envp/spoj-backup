/*Code to compute the number of cards for a an stable overhang of 'c', cards are stacked so that successive overhangs form {1/j}
*/
#include <stdio.h>

int main() {
    double c;
    while(1) {
        double sum=0,i=1;
          scanf("%lf",&c);
          if(c==0) {break;}
          else {
                while(sum<c) {
                    sum+=1/(i+1);
                    ++i;
                }
          printf("%d card(s)\n", (int)i-1);  
          }
    }
    return 0;
}
