#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int dp[15][15][15][2][2][2];
int num[15];
ll dfs(int pos,int u, int v, int state, int n8, int n4, int limit){
	ll ans = 0;
	if(n8 && n4)
		return 0;
	if(pos == 0)
		return state;
	if(!limit && dp[pos][u][v][state][n8][n4] != -1)
		return dp[pos][u][v][state][n8][n4];
	int up = limit ? num[pos]:9;
	for(int i =  0; i <= up; ++i){
		ans += dfs(pos-1, i, u, state || (i == u && i ==v), n8 ||(i == 8),n4 ||( i == 4), limit && (i == up));
	}
	if(!limit)	dp[pos][u][v][state][n8][n4] = ans;
	return ans;
}
ll solve(ll x){
	int len = 0;
	while(x){
		num[++len] = x % 10;
		x/=10;
	}
	if(len!=11)
		return 0;
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for(int i = 1; i <= num[len]; ++i){
		ans += dfs(len-1,i,0,0,i==8,i==4,i == num[len]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a-1);
	return 0;
}