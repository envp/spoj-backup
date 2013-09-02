#include<stdio.h>
#include<string.h>
p[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
int main(t,a,r){long long unsigned b;char s[1001];scanf("%d\n",&t);while(t--){scanf("%s %llu",&s,&b);a=s[strlen(s)-1]-48;if(!b)r=1;else{b=(b%=4)-1;r=(b+1)?p[a][b]:p[a][3];}printf("%d\n", r);}exit(0);}
