#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
vector<pii>e[maxn];
int vis[maxn];
bool flag;
void dfs(int u){
	if(!e[u].size())
		return;
	int mx = 0, t = 0;
	for(auto it : e[u]){
		if(it.se > mx){
			mx = it.se;
			t = it.ff;
		}
	}
	if(t && !vis[t]){
		flag = true;
		vis[t] = 1;
		cout << t << ' ' << mx << '\n';
		dfs(t);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		e[x].pb({y,z});
	}
	dfs(1);
	if(!flag)
		cout << "none";
	return 0;
}