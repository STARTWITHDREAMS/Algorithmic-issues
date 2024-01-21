#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const ll inf = 1e9+5;
ll a[105], topo[4];
int n, m;
ll ans = inf;
int e[105][105];
bool check(int x, int y, int z){
	if(e[x][y] && e[x][z] && e[y][z])
		return true;
	return false;
}
void solve(int num, int st, ll sum){
	if(st > n)
		return;
	topo[num] = st;
	if(num == 3){
		if(check(topo[1], topo[2], topo[3]))
			ans  = min(ans, sum);
	    return;
	}
	for(int i = st+1; i <= n; ++i){
		solve(num + 1, i, sum + a[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin  >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		e[u][v] = 1;
		e[v][u] = 1;
	}
	for(int i = 1; i <= n; ++i)
		solve(1, i, a[i]);
	cout << (ans == inf? -1 : ans);
	return 0;
}