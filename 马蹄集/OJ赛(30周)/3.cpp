#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 4e4+5;
vector<int>e[maxn];
int n, m, t, f;
ll te,fe,s;
const ll inf = 0x3f3f3f3f;
void bfs(vector<ll>&dis, int st){
	for(auto &it : dis)
		it = inf;
	dis[st] = 0;
	queue<int>q;
	vector<int>vis(n+1);
	q.push(st);
	vis[st] = 1;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(auto it : e[tmp]){
			if(vis[it])
				continue;
			dis[it] = dis[tmp] + 1;
			q.push(it);
			vis[it] = 1; 
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >>  te >> fe >> s >> t >> f >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x,y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}	
	vector<ll>dis1(n+1),dis2(n+1),dis3(n+1);
	bfs(dis1,t);	bfs(dis2,f);	bfs(dis3,n);
	ll ans = inf;
	for(int i = 1; i <= n; ++i){
		if(dis1[i] == inf || dis2[i] == inf || dis3[i] == inf)\
			continue;
		ans = min(ans, te * dis1[i] + fe * dis2[i] + (te+fe-s) * dis3[i]);
	}
	cout << (ans == inf ? -1: ans) ;
	return 0;
}