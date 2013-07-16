#include<stdio.h>
#include<math.h>
main(){int n,u;scanf("%d",&n);while(n--){scanf("%d",&u);printf("%.5lf\n",floor(0.5+50000*(1-pow(u*u+u+1,-1)))/100000);}return 0;}
