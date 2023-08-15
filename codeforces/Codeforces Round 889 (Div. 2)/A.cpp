#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			if(x == i)
				cnt++;
		}
		int ans = cnt/2  + cnt % 2;
		cout << ans << '\n';
	}
	return 0;
}