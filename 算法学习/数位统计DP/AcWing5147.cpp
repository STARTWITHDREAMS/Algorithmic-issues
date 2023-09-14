#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int dp[15][2][2];
int num[15];
ll dfs(int pos,int lead, int limit){
	ll ans = 0;
	if(pos == 0 && !lead)
		return 1;
	if(dp[pos][lead][limit] != -1)
		return dp[pos][lead][limit];
	int up = limit? num[pos] : 9;
	for(int i = 0; i <= up; ++i){
		if(i == 0 && lead){
			ans += dfs(pos - 1, 1, limit && i == up);
		}else if(i == 4 || i == 7){
			ans += dfs(pos - 1, 0, limit && i == up);
		}
	}
	return dp[pos][lead][lead]  = ans;
}
ll solve(ll x){
	int len = 0;
	memset(dp, -1, sizeof(dp));
	while(x){
		num[++len] = x % 10;
		x /= 10;
	}
	return dfs(len,1,1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}