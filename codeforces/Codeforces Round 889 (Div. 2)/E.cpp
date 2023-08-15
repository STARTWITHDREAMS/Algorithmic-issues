#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
const ll mod = 1000000007;
ll a[505];
ll dp[505][505];
ll quickpow(ll a, ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1)
			res = (res * a) % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	ll sum = 0;
	cin >> n >> m;
	ll inv2 = quickpow(2, mod-2);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	a[n+1] = m + 1;
	for(int i = 1;i <= m; ++i)
		dp[i][m+1] = m+1-i;
	for(int i = m; i>=1; --i){
		for(int j = m; j > i; --j){
			dp[i][j] = inv2*((dp[i+1][j]+1)%mod+dp[i][j+1]%mod) % mod;
		}
	}
	for(int i = 1; i <= n; ++i){
		sum = (sum + dp[a[i]][a[i+1]]) % mod;
	}
	cout << sum;
	return 0;
}