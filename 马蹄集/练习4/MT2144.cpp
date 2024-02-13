#include<bits/stdc++.h>


long long  dp[105];
int main(){
	dp[0] = 1;
	int m, n;
	long long  ans = 0;
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m * (n-1); ++i){
			dp[i] =  dp[i-1] + dp[i-2];
		ans = dp[i];
	}
	printf("%lld", ans);
}
