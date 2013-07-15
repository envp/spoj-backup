/**
*	Recently in Farland, a country in Asia, the famous scientist Mr. Log Archeo discovered ancient pyramids.
*	But unlike those in Egypt and Central America, they have a triangular (not rectangular) foundation.
*	That is, they are tetrahedrons in the mathematical sense.
*	In order to find out some important facts about the early society of the country 
*	(it is widely believed that the pyramid sizes are closely connected with Farland's ancient calendar),
*	Mr. Archeo needs to know the volume of the pyramids. Unluckily, he has reliable data about their edge lengths only.
*	t [number of tests to follow]
*	In each of the next t lines six positive integer numbers not exceeding 1000 separated by spaces
*	(each number is one of the edge lengths of the pyramid ABCD). The order of the edges is the following: AB, AC, AD, BC, BD, CD.
*/
#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b,c,d,e,f;
        double V;
        scanf("%d %d %d %d %d %d", &a, &b, &c,&d,&e,&f);
        double A=a*a, B=b*b, C=c*c, D=d*d, E=e*e, F=f*f;
        V = sqrt(A*F*(-A-F+B+E+C+D)+ B*E*(A+F-B-E+C+D) + C*D*(A+F+B+E-C-D) - (A+F)*(B+E)*(C+D)/2 + (A-F)*(B-E)*(C-D)/2)/12;
        printf("%.4lf\n", V);
    }
    return 0;
}