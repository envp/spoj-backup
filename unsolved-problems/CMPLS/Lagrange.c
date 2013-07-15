/* Lagrange Polynomial */

#include <math.h>
#include <stdio.h>

main()
{
float x[12],y[12];
float xtem,ytem;
int points,i,j,count;
float xval,temp,total;

scanf("%d %f\n",&points,&xval);
printf("number of points = %d xvalue to calculate = %f\n",points,xval);
printf("\nx       y\n");
for (i=0;i<points;i++){
        scanf("%f %f\n",&xtem,&ytem);
        x[i] = xtem; y[i] = ytem;
        printf("%f %f\n",xtem,ytem);
}
total = 0.0;
for (i=0;i<points;i++){
        temp = 1.;
        for(j=0;j<points;j++){
                if (j != i) {
                        temp = temp * (xval - x[j]) / (x[i] - x[j]);
                }
        }
        temp *= y[i];
        total += temp;
}
printf("The value of the function at x = %f is y = %f\n\n\n",xval,total);
}
