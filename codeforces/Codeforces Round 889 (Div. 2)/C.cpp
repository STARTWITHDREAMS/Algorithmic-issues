#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
void solve(){
	int n;
	cin >> n;
	vector<ll>a(n+1);
	vector<pii>ans;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	ll maxx = -25;
	ll minx = 25;
	int idmax = 0, idmin = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] > maxx){
			maxx = a[i];
			idmax = i;
		}
		if(a[i] < minx){
			minx = a[i];
			idmin = i;
		}
	}
	int cnt = 0;
	if(maxx <= 0){
		for(int i = n - 1; i >= 1; --i){
			while(a[i] > a[i+1]){
				a[i] += minx;
				cnt++;
				ans.pb({i,idmin});
			}
			if(a[i] < minx){
				minx = a[i];
				idmin = i;
			}
		}
	}else if(minx >= 0){
		for(int i = 2; i <= n; ++i){
			while(a[i] < a[i-1]){
				a[i] += maxx;
				cnt++;
				ans.pb({i,idmax});
			}
			if(a[i] > maxx){
				maxx = a[i];
				idmax = i;
			}
		}
	}else if(maxx >= -minx){
		for(int i = 2; i <= n; ++i){
			while(a[i] < a[i-1]){
				a[i] += maxx;
				cnt++;
				ans.pb({i,idmax});
			}
			if(a[i] > maxx){
				maxx = a[i];
				idmax = i;
			}
		}
	}else{
		for(int i = n - 1; i >= 1; --i){
			while(a[i] > a[i+1]){
				a[i] += minx;
				cnt++;
				ans.pb({i,idmin});
			}
			if(a[i] < minx){
				minx = a[i];
				idmin = i;
			}
		}
	}
	cout << cnt << '\n';
	for(auto it : ans){
		cout << it.ff << ' ' << it.se << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}