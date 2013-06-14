/*What is the radius of sphere inscribed within an irregular tetrahedron (Not always possible) ?
**Will be finding that out using Pierro della Francesca's Tetrahedron Formula
**For finding maximum radius of sphere, iterate 15 times for each side pairing current = {a,f},{b,e},{c,d} , PITA. NO SHIT. I BET THIS CODE IS SLOW AS FUCK TOO.
*/

#include <stdio.h>
#include <math.h>

double area(int x, int y, int z);

int main() {
    int n;
    scanf("%d", &n);
    while(n) {
        int a,b,c,d,e,f;
        double V,S,r;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        double A=a*a, B=b*b, C=c*c, D=d*d, E=e*e, F=f*f;
        V = sqrt(A*F*(-A-F+B+E+C+D)+ B*E*(A+F-B-E+C+D) + C*D*(A+F+B+E-C-D) - (A+F)*(B+E)*(C+D)/2 + (A-F)*(B-E)*(C-D)/2)/12;
        S = area(a,c,e)+area(a,b,d)+area(b,c,f)+area(d,e,f);
        r=3*V/S;
        printf("%.4lf\n",r);
        --n;
    }
    return 0;
}

double area(int x, int y, int z) {    
    double a=(double)x; //C, Y U NO HAVE AUTOMATED TYPECASTING??? -___-
    double b=(double)y;
    double c=(double)z;
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
