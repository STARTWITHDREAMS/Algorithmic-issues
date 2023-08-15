#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
const ll mod = 1000000007;
int m, n;
int a[505];
int vis[505][505],f[505][505];
ll inv2;
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
ll dp(int x, int y){
	if(x == y){
		return m+1-x;
	}
	if(y == m + 1)
		return 0;
	if(vis[x][y])
		return f[x][y];
	vis[x][y] = 1;
	f[x][y] = (inv2 * dp(x+1,y) + inv2*dp(x,y+1)) % mod;
	return f[x][y];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	inv2 = quickpow(2, mod-2);
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i){
		ans = (ans + m+1-a[i]) % mod;
	}
	for(int i = 1; i < n; ++i){
		ans  =  (ans - dp(a[i],a[i+1]) + mod) % mod;
	}
	cout << ans;
	return 0;
}