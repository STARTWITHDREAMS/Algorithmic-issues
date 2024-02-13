#include<bits/stdc++.h>
const long long mod = 1e9+7;
long long dp[1005];
int main(){
	dp[0] = 1;
	int x, n, m, k;
	scanf("%d %d %d %d", &x, &n, &m, &k);
	for(int i = 1; i <= x; ++i){
		if(i - n >= 0)
			dp[i] = (dp[i] + dp[i-n]) % mod;
		if(i - m >= 0)
			dp[i] = (dp[i] + dp[i-m]) % mod;
		if(i - k >= 0)
			dp[i] = (dp[i] + dp[i-k]) % mod; 
	}
	if(dp[x] == 0)
		printf("impossible");
	else
		printf("%lld", dp[x]);
}