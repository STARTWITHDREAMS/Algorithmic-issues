#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int n, m;
int topo[maxn];
void dfs(int st, int cur){
	if(n - st + 1 < m - cur)
		return;
	if(cur == m){
			//cout << 1 << endl;
			for(int i = 1; i <= cur; ++i)
				cout << topo[i] << ' ';
			cout << '\n';
			return;
		}
	for(int i = st; i <= n; ++i){
		topo[cur+1]  =  i;
		dfs(i+1,cur+1);		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	dfs(1,0);
	return 0;
}