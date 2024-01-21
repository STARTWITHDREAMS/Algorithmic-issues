#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
pii a[maxn];
bool cmp(pii x, pii y){
	if(x.ff == y.ff){
		return x.se > y.se;
	}
	return x.ff < y.ff;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int p, v;
		cin >> p >> v;
		a[i].ff = p; a[i].se = v;
	}
	sort(a+1, a+n+1, cmp);
	for(int i = 1; i <= n; ++i){
		cout << a[i].ff << ' ' << a[i].se << endl;
	}
	int sum = 1, ans = 1;
	for(int i = 2; i <= n; ++i){
		 if(a[i].ff == a[i-1].ff || a[i].se < a[i-1].se){
		 	sum++;
		 	ans = max(ans, sum);
		 }else{
		 	sum = 1;
		 }
		 cout << ans << endl;
	}
	cout << ans;
	return 0;
}