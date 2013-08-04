#include <stdio.h>

inline void fastRead(int *a);

int main() {
	int n, k, temp, count = 0;
	char c;
	scanf("%d %d\n", &n, &k);
	while(n--) {
		fastRead(&temp);
		if(temp % k == 0) {
			++count;
		}
	}
	printf("%d\n", count);
	return 0;
}
/* Reads a line */
inline void fastRead(int *a) {
	register char c=0;
 	while (c<33){
	 	c = getchar();
	 }
 	*a=0;
 	while (c>33)
 	{
	     *a = *a * 10 + c - '0';
	     c = getchar();
 	}
}
