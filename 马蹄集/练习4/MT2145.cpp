#include<bits/stdc++.h>
const long long mod = 114584;
const int N = 1e5+5;
long long dp[N];
int main(){
	int n, k;
	dp[0] = 1;
	scanf("%d %d", &n, &k);
	for(int i = 1;  i <= n;  ++i){
		for(int j = 1; j <= k; ++j){
			if(i-j<0)
				continue;
			dp[i] = (dp[i] + dp[i-j]) % mod;
		}
	}
	printf("%lld", dp[n]);
}