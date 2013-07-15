#include <stdio.h>

int main (void) {
    int i, turns;                                     	/* number of iterations of program, (i) used in iteration later */
    long long int ap2d, apn_3d;                         /* hold the terms of the ap */
    long long int sum;                                  /* hold the sum of the ap */
    long long int count, a, d;                          /* hold the number of elements in the ap, the first element and the common difference */

    scanf("%d", &turns);
    while (turns--) {
        scanf("%lld %lld %lld", &ap2d, &apn_3d, &sum);  /* get input */

        if ( !sum ) {                                   /* there are no unique solutions in cases where sum is zero */
            return 1;
        }

        count = 2 * sum / (ap2d+apn_3d);                /* how many elements are in the ap ? */
        d = (apn_3d-ap2d) / (count-5);                  /* the common difference */
        a = ap2d - (2 * d);                             /* the first term */

        printf("%lld\n", count);                        /* print the number of items in the ap */
        for (i=0; i<count; i++) {                       /* the loop prints the ap */
            printf("%lld ", a+(i*d));
        }
        printf("\n");
    }                                                   /* repeat */
    return 0;
}
