#include <stdio.h>
#include <string.h>

#define MAX 1000

//int add(int a[], int b[]);
//int sub(int a[], int b[]);
//int mul(int a[], int b[]);

int main() {
	int *n1, *n2;
	char op = '\0';
	char *input;
	int t;
	scanf("%d", &t);
	while(t>0) {
		scanf("%s", input);
		while(*input !='\0') {
			printf("in while\n");
			//Since, Input format 123214153151515....OP....28471895719571 with OP = {+,-,*}
			if((!(*input == '+' || *input == '-' || *input == '*') && op == '\0')) {	//Operator is not set
				*n1 = (*input) - '0';
				printf("%d", *n1);
				++n1;
				++input;
			}
			else if(*input == '+' || *input == '-' || *input == '*') {	//Record operator
				op = *input;
				++input;
			}
			else if((!(*input == '+' || *input == '-' || *input == '*') && op != '\0')) {	//Operator has been recorded
				*n2 = (*input) - '0';
				printf("%d", *n2);
				++n2;
				++input;
			}
		}
		switch(op) {
			case '+':
				printf("add");
				//add(n1,n2);
				break;
			case '-':
				printf("sub");
				//sub(n1,n2);
				break;
			case '*':
				printf("mul");
				//mul(n1,n2);
				break;
			default:
				printf("Illegal Character");	//debug
				break;
			}
		t--;
	}
	return 0;
}

//int add(int a[], int b[]) {
//	return 0;
//}
//int sub(int a[], int b[]) {
//	return 0;
//}
//int mul(int a[], int b[]) {
//	return 0;
//}

