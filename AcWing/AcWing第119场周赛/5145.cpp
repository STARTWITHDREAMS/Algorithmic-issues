#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
bool flag  = false;
int m,n;
int vis[55][55];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char mp[55][55];
void dfs(int x, int y, int ox, int oy){
	for(int i = 0; i < 4; ++i){
		int newx = x + dir[i][0];
		int newy = y + dir[i][1];
		if(flag)
			break;
		if(newx > n || newy > m || newx < 1 || newy < 1 || mp[newx][newy] != mp[x][y])
			continue;
		if(newx == ox && newy == oy)
			continue;
		if(vis[newx][newy]){
			flag = true;
			return;
		}
		vis[newx][newy] = 1;
		dfs(newx, newy, x, y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			cin >> mp[i][j];
		}
	for(int i = 1; i <= n; ++i){
		for(int j  = 1; j <= m; ++j){
			if(vis[i][j])
				continue;
			vis[i][j] = 1;
			dfs(i,j,0,0);
		}
	}
	if(flag)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}