#include <stdio.h>
#include <stdlib.h>

int main() {
    int t = 0;
    int n, k;
    while(1)
    {
        ++t;
        scanf("%d",&n);
        if(n == -1)
            break;
        printf("Case %d:\n",t);
        int i;
        int *c = malloc(( n + 1) * sizeof(int));
        for(i = n; i >= 0; i--)
            scanf("%d", &c[i]);
        scanf("%d",&k);
        while(k--) {
            int x;
            int y = 0;
            scanf("%d", &x);
            for(i=n;i>=0;i--) {
                y = y * x + c[i];
            }
            printf("%d\n", y);
        }
        free(c);
    }
    return 0;
}
