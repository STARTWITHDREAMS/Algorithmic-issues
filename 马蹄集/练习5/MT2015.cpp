#include<bits/stdc++.h>
int main(){
	long long n, d, m, l;
	scanf("%lld %lld %lld %lld", &n, &d, &m, &l);
	long long ans = 0;
	for(long long i = 1; ; ++i){
		long long t  = i*d/m;
		long long  tt = d * 1LL*i % m;
		if(t > n){
			ans =  i;
			break;
		}
		if(tt > l){
			ans = i;
			break;
		}
	}
	printf("%lld", ans*d);
	return 0;
}