#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int i64_t;

const i64_t p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void countdigitsum(char *num, int p, i64_t *cnt);

int main() {
	int n1, n2, i;
	i64_t c1[10], c2[10], sum;
	char s1[11], s2[11];
	while(scanf("%d %d", &n1, &n2)==2 && n1>-1) {
		memset(c1, 0, sizeof c1); // n1-1
		memset(c2, 0, sizeof c2); // n2
		if(n1 > 1) {
			sprintf(s1, "%d", n1-1);
			countdigitsum(s1, strlen(s1)-1, c1);
		}
		if(n2 > 0) {
			sprintf(s2, "%d", n2);
			countdigitsum(s2, strlen(s2)-1, c2);
		}
		for(sum = 0, i = 1; i < 10; i++) {
			sum += (c2[i] - c1[i]) * i;
			}
		printf("%lld\n", sum);
	}
	return 0;
}

void countdigitsum(char *num, int p, i64_t *cnt) {
	int i, now, last;
	if(!p) {
		for(i = 0; i <= *num-'0'; i++) cnt[i]++;
		return;
	}
	for(i = 0; i < *num-'0'; i++) cnt[i] += p10[p];
	for(i = 0; i < 10; i++) cnt[i] += (i64_t)(*num-'0') * p * p10[p-1];
	last = (*num - '0') * p10[p];
	sscanf(num, "%d", &now);
	cnt[*num-'0'] += now - last + 1;
	countdigitsum(&num[1], p-1, cnt);
}
