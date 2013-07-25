/*	There are G girl students and B boy students in a class.
*	We need to arrange them in a single row, but arrangement of students should be in order to minimize the gender regularity^.
*	Find the minimum gender regularity among all possible arrangements.
*
	^The gender regularity of an arrangement is the maximum number of students of the same gender (all girls or all boys) that appear consecutively.
*/

#include <stdio.h>
#include <math.h>
int main() {
	int girls, boys, min_regularity;
	while(1) {
		scanf("%d %d", &girls, &boys);
		if(girls == -1 && boys == -1) {
			break;
		}
		else {
			if(girls == 0 && boys == 0) {
				min_regularity = 0;
			}
			else {
				if (girls == boys) {
					min_regularity = 1;
				}
				else if(girls > boys) {
					min_regularity = ceil( (double)girls /( (double)boys + 1) );
				}
				else {
					min_regularity = ceil( (double)boys /( (double)girls + 1) );
				}
			}
		}
		printf("%d\n", min_regularity);
  	}
	return 0;
}
