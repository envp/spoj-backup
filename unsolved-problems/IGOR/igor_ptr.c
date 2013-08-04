
/* Portal sucks stuff in from the left */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_MAX_LENGTH 14
#define PROTON '+'
#define ELECTRON '-'
#define SUCCESS 42

inline int readChain(char *chain, int n);
inline int portalThatSucksStuffIn(char *chain, int chain_length);

int main() {
    int t, n, k, i, j = 0;
    int time_interval;
    scanf("%d", &t);
    static int unique, max_perms;
        while(t > 0) {
                unique = 0, max_perms = 0;
                ++j;
                printf("Experiment #%d:\n", j);
                scanf("%d %d", &n, &k);
                char *chain = malloc(( n + 1) * sizeof(char));
                max_perms = (int)pow(2, n);                                                        	/* Absolute maximum no. of permutation */
//              printf("[DBG]: max_perms = %d\n", max_perms);
                char **state = (char **)malloc(max_perms * sizeof(char *));             			/* Variable to store the unique arrangements */
                if(chain != NULL) {
                        state[0] = malloc(n * sizeof(char));                                        /* Base state */
                        readChain(chain, n);                                                       	/* Reading from stdin */
                        memcpy(state[0], chain, n * sizeof(char));

                        for(i = 1; i < max_perms; ++i) {                                           	/* Entering the portal */
                                state[i] = malloc(n * sizeof(char));                               	/* http://stackoverflow.com/questions/7179187/2d-array-using-a-double-pointer-and-malloc-function */

                                portalThatSucksStuffIn(chain, n);                                  	/* Simulate 1 more cycle */
                                memcpy(state[i], chain, n * sizeof(char));

//                              printf("[DBG]: k = %d\n", k);
//                              printf("[DBG]: iteration %d => %s\n", i, state[i]);
                                ++unique;
                                if(i != 0 && strcmp(state[i], state[0]) == 0) {                 	/* Break if we hit the original state again, else we have another unique arrangement */
//                                      printf("[DBG]: BREAKING FROM LOOP ...\n");
                                        break;
                                }
                        }
//                      printf("[DBG]: unique = %d\n", unique);
                        while(k > 0) {
                                scanf("%d", &time_interval);
                                time_interval %= unique;
//                              printf("[DBG]: %d\n", time_interval);
                                printf("%s\n", state[time_interval]);
                                k--;
                        }
                }
                else {
                        printf("SIGSEGV : EXITING WITH STATUS 1");
                        exit(1);
                }
                free(chain);
                free(state);
                t--;
        }
        return 0;
}

inline int readChain(char *chain, int n) {                               							/* Read pattern into an array */
        char temp[INPUT_MAX_LENGTH + 1];
        scanf("%s", temp);
        memcpy(chain, temp, n*sizeof(char));
//      printf("[DBG]: chain => %s\n", chain);
        return SUCCESS;
}

inline int portalThatSucksStuffIn(char *chain, int n) {             								/* Simulate 1 cycle of the portal */
    char temp;
    int i;
    if(*(chain) == PROTON) {                                                  						/* Spontaneous Flipping */
    if(*(chain + n - 1) == ELECTRON) {
            *(chain + n - 1) = PROTON;
    }
    else {
            *(chain + n - 1) = ELECTRON;
    }
    }
    temp = *chain;
    for(i = 0; i < n; ++i) {                                                                  		/* Left shift */
            *(chain + i) = *(chain + i + 1);
    }
    *(chain + n - 1) = (temp == PROTON) ? ELECTRON : PROTON;        								/* Flipped particle appended to end */
    return SUCCESS;
}

