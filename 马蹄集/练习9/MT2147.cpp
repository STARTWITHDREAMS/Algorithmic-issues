#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 4e6+5;
ll dp[N], sum[N];
int main(){
	sum[0] = 1;
	ll n, m;
	scanf(" %lld %lld", &n, &m);
	for(int i = n - 1; i >= 1;--i){
		dp[i] = (dp[i] + sum[n - i - 1]) % m;
		int cnt = 2;
		int L = cnt * i, R = cnt * (i+1);
		while(L <= n){
			if(R <= n){
				dp[i] = (dp[i] + sum[n-L] - sum[n-R]) % m;
			}else{
				dp[i] = (dp[i] + sum[n-L]) % m;
			}
			cnt++;
			L = cnt * i;
			R = cnt * (i+1);
		}
		sum[n-i] = (sum[n-i-1]  + dp[i]) % m;
	}
	printf("%lld", dp[1]);
	return 0;
}