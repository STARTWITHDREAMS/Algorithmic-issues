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
	vector<int>a(n+1);
	vector<pii>ans1, ans2;
	int sum1 = 0, sum2 = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int cnt1 = 0, cnt2 = 0;
	int idx = 0, idy = 0;
	int maxx = -25, minn = 25;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i){
		if(a[i] < minn){
			idy = i;
			minn = a[i];
		}
		if(a[i] > maxx){
			idx = i;
			maxx = a[i];
		}
		if(a[i] < 0)
			y1++;
		if(a[i] > 0)
			y2++;
	}
	if(minn + maxx < 0){
		if(maxx > 0){
			while(minn + maxx < 0){
				ans1.pb({idx,idx});
				x1++;
				maxx += maxx;
			}
			cnt1 += x1;
			for(int i = 1; i <= n; ++i){
				if(a[i] < 0){
					ans1.pb({i,idx});
				}else if(a[i] > 0){
					ans2.pb({i,idy});
				}
			}
			cnt1 += y1;
			cnt1 += n-1;
			cnt2 += (y2 + n-1);
			if(cnt1 < cnt2){
				cout << cnt1 << '\n';
				for(auto  it : ans1){
					cout << it.ff << ' ' << it.se << '\n';
				}
				for(int i = 2; i <= n; ++i)
					cout << i << ' ' << i-1 << '\n';
			}else{
				cout << cnt2 << '\n';
				for(auto it : ans2){
					cout << it.ff << ' ' << it.se << '\n';
				}
				for(int i = n-1; i >= 1; --i){
					cout << i << ' ' << i + 1 << '\n';
				}
			}
		}else{
			cout << n-1 << '\n';
			for(int i = n-1; i >= 1; --i){
				cout << i << ' ' << i+1 << '\n';
			}
		}
	}else{
		if(minn < 0){
			while(minn + maxx > 0){
				ans2.pb({idy,idy});
				x2++;
				minn += minn;
			}
			cnt2 += x2;
			for(int i = 1; i <= n; ++i){
				if(a[i] > 0){
					ans2.pb({i,idy});
				}else if(a[i] < 0){
					ans1.pb({i,idx});
				}
			}
			cnt2 += y2;
			cnt2 += n-1;
			cnt1 += (y1 + n-1);
			if(cnt2 < cnt1){
				cout << cnt2 << '\n';
				for(auto  it : ans2){
					cout << it.ff << ' ' << it.se << '\n';
				}
				for(int i = n-1; i >= 1; --i)
					cout << i << ' ' << i+1 << '\n';
			}else{
				cout << cnt1 << '\n';
				for(auto it : ans1){
					cout << it.ff << ' ' << it.se << '\n';
				}
				for(int i = 2; i <= n; ++i){
					cout << i << ' ' << i - 1 << '\n';
				}
			}
		}else{
			cout << n-1 << '\n';
			for(int i = 2; i <= n; ++i){
				cout << i << ' ' << i-1 << '\n';
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}