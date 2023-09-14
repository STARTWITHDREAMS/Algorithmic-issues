#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 15;
ll dp[15][15][2][2];
int num[15];
ll dfs(int pos, int last, bool lead, bool limit){
	ll ans = 0;
	if(pos == 0)
		return 1;
	if(dp[pos][last][lead][limit] != -1)
		return dp[pos][last][lead][limit];
	int up = (limit ? num[pos] : 9);
	for(int i = 0; i <= up; ++i){
		if(abs(last-i)>=2){
			if(i == 0 && lead)
				ans += dfs(pos-1, -2, true, limit && i == up);
			else{
				ans += dfs(pos-1, i, false, limit && i == up);
			}
		}
	}
	return dp[pos][last][lead][limit] = ans;
}
ll solve(ll x){
	int len = 0;
	while(x){
		num[++len] = x % 10;
		x/=10;
	} 
	memset(dp,-1,sizeof(dp));
	return dfs(len,-2,true,true);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin >> a >> b;
	cout << solve(b) - solve(a-1);
	return 0;
}