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
	for(int i = 1;i <= n; ++i){
		ll mx  = 0, t = 0;
		if(!e[i].size()){
			cout << 0 << '\n';
			continue;
		}
		for(auto it : e[i]){
			if(it.se > mx){
				mx = it.se;
				t = it.ff;	
			}
		}
		cout << t << ' ' << mx << '\n';
	}
	return 0;
}