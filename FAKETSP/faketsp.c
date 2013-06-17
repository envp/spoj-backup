#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define KEY_TO_SUCCESS 2

struct point {
    double x;
    double y;
};
typedef struct point vertex;

double dist(vertex a, vertex b);

int main() {
	vertex a, b;
	double total = 0;
	//I love scanf's format string
	scanf("%*[^(](%lf, %lf).", &a.x, &a.y);

	//Seems like scanf returns 2 on a successful read
	while(scanf("%*[^(](%lf, %lf).", &b.x, &b.y) == KEY_TO_SUCCESS) {
		total += dist(a,b);;
		printf("The salesman has traveled a total of %.3lf kilometers.\n", total);
		//Save last point
        //Next step: write this as a linked list problem
        a = b;
	}

	return 0;
}
double dist(vertex a, vertex b) {
	//Euclidean 2-norm?
	//Sorry, had to say it.
	double k = ( a.x - b.x )*( a.x - b.x ) + ( a.y - b.y )*( a.y - b.y );
	return sqrt(k);
}
