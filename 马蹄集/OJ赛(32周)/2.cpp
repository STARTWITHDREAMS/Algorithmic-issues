#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int inf = 1e5+5;
int e[9][9], vis[15];
int n, ans = inf;
void dfs(int u, int sum, int cnt){
	if(cnt == n-1){
		ans = min(ans, sum + e[u][1]);
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(i != u && !vis[i]){
			vis[i] = 1;
			dfs(i, sum + e[u][i], cnt+1);
			vis[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> e[i][j];
	vis[1] = 1;
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}