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
		ll n;
		cin >> n;
		ll ans= 1;
		for(ll i = 2;i <= n; ++i){
			if(n % i != 0)
				break;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}