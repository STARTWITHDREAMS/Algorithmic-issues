#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
vector<pii>e[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		e[x].pb({y,z});
	}
	ll t = 0, mx = 0;
	for(int i = 1; i <= n; ++i){
		if(e[i].size() > mx){
			t = i;
			mx = e[i].size();
		}
	}
	cout << t << '\n';
	sort(e[t].begin(),e[t].end());
	for(auto it : e[t]){
		cout << it.ff << ' ' << it.se << '\n';
	}
	return 0;
}