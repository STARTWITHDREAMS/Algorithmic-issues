#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int a[maxn];
ll s[2*maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	bitset<2*maxn>dp;
	dp.set(a[1]);
	dp.reset(0);
	ll ans = a[1];
	for(int i = 2; i <= n; ++i){
		if(dp.test(i-1)){
			ans = max(ans, s[i] - (i-1));
		}
		dp |= dp << a[i];
		dp.reset(i-1); 
	}
	for(int i = n + 1; i <= 2 * n; ++i){
		if(dp.test(i-1)){
			ans = max(ans, s[n] - (i-1));
		}
	}
	cout << ans;
	return 0;
}