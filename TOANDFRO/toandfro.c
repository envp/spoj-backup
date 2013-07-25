#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

int main() {
    int rows, columns;															/* Columns to process */
    int zone, position, input_size, i, j;				         		        /* Counters for read-zone, characters read, input size*/
    char text[MAX_LENGTH] = {'\0'};
	char message[MAX_LENGTH] = {'\0'};
	while(1) {                                                          		/* Main loop */
		scanf("%d\n", &columns);                                        		/* Get no. of columns to process */
		if(columns == 0) {
			break;
		}
		else {
			int chars_read = 0;
			scanf("%s", text);
			input_size = strlen(text);
			rows = input_size/columns;
			while(chars_read < input_size) {
				zone = chars_read/columns;                                  	/* Divide into reading zones */
				if(zone%2 == 1) {                                           	/* Odd zones need to reverse reading */
					position =  (zone + 1)*columns - (chars_read%columns + 1);
					message[chars_read] = text[position];
				}
				else {                                                      	/* Even zones are read normally */
					position = chars_read;
					message[chars_read] = text[position];
				}
				++chars_read;
			}
			for(i = 0; i < columns; ++i) {
				for(j = 0; j < rows; ++j) {
					printf("%c",message[j*columns + i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

