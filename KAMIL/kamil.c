#include<stdio.h>
main(){char c;int p=1;while((char c=getchar())!=-1){if(c==10)printf("%d\n",p),p=1;p*=(c==68||c==70||c==76||c==84)?2:1;}return 0;}
