#include <stdio.h>

int main() {
	int a1, a2, a3;										/*	Variables to hold AP/GP terms	*/
	while(1)	{ 										/*	Alternate implementation => while( scanf("%d %d %d", &a1, &a2, &a3) == 3 && a1 != 0 && a2 != 0 && a3 != 0 ) {//code}	*/
		scanf("%d %d %d", &a1, &a2, &a3);
		if(a1 == 0 && a2 == 0 && a3 == 0 ) {			/*	stdin must have 3 non-zero integers for execution of loop	*/
			break;
		}
		else {
														/*	Test for AP	*/
			if( a3 + a1 == 2*a2) {
				printf("AP %d\n", a3 + a2 - a1 );
			}
			else if(a3 * a1 == a2 * a2) {				/*	Test for GP	*/
				printf("GP %d\n", a3 * ( a2 / a1 ) );
			}
			else {										/*	Not our concern, also serves as a redundant debug	*/
				printf("123445114131 !\n");
				break;
			}
		}
	}
	return 0;
}