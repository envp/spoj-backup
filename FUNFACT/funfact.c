#include <stdio.h>
#include <math.h>

long long stirling(long long k) {
        double ret,n=k*1.0;
        ret = .5 * log((2.*n + 1./3.) * M_PI) + n*(log(n) - 1.);
        return ((long long)(ret*log10(M_E))+1LL);
}
int main() {
    long long t,n;
    for(scanf("%lld",&t);t>0;t--) {
        scanf("%lld",&n);
        n++;
        long long  lo=1LL,hi=1LL<<31,mid;
        while(lo<hi) {
            mid=(lo+hi)>>1;
            if(stirling(mid)<n) lo=mid+1;
            else hi=mid;
        }
        mid=(lo+hi)>>1;
        printf("%lld\n",mid-1);
   }
	return 0;
}
