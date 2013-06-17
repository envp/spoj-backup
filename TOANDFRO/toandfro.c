#include <stdio.h>
#include <string.h>

int main() {
    int n,l,i,j;
    char *ctxt, *ptxt;
    while(1) {
        scanf("%d",&n);
        if(n==0) {
			break;
			}
        else {
            scanf("%s", ctxt);
            l=strlen(ctxt);
            for(i=0; i<l; i++) {
                for(j=n*i; j<l; j+=n) {
                    int k=j/n;
                    *(ptxt+k)=*(ctxt+j);
                }
            }
            printf("%s", *ptxt);
        }
    }
    return 0;
}
