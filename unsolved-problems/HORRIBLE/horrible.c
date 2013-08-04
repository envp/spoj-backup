#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;

int main() {
    int op;
    int indexL;
    int indexH;
    int add;
    int t, i, n, c, x,*array;
	static i64_t sum;
    scanf("%d\n", &t);
    while(t > 0) {
        scanf("%d %d\n", &n, &c);
        array = (int *) malloc( n * sizeof(int));
        memset(array, 0, n * sizeof(int));
        while(c > 0){
            ++x;
			scanf("%d %d %d %d\n", &op, &indexL, &indexH, &add);      //issue
            printf("%d ", op);
			if(op == 0) {
				for(i = indexL; i <= indexH; ++i) {
					*(array + i) += add;
				}
			}
			else {
				sum = 0;
				for(i = indexL; i <= indexH; ++i) {
					sum += *(array + i);
				}
				printf("%d %lld\n", x, sum);
			}
            --c;
        }
        --t;
    }
    return 0;
}
