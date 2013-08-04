#include <stdio.h>

typedef long long int i64_t;

int main() {
    i64_t money, n_fences, budget_per_plot, sustenance;
    i64_t n_plots, expenditure, money_left;
    while(1) {
		scanf("%lld %lld %lld %lld", &money, &n_fences, &budget_per_plot, &sustenance);
		if(money == 0 && n_fences == 0 && budget_per_plot == 0 && sustenance == 0) {
			break;
		}
		else {
			n_plots = ( n_fences * (n_fences + 1) )/2 + 1;
			expenditure = budget_per_plot * n_plots;
			money_left = money - expenditure - sustenance;
			if(money_left >= 0) {
				printf("Farmer Cream will have %lld Bsf to spend.\n", money_left + sustenance);
			}
			else {
                money_left *= -1;
				printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", money_left);
			}
		}
	}
	return 0;
}
