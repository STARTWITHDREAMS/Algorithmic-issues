#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
ll dp[20];
ll num[15], ten[20];
ll cnta[20], cntb[20];
void init(){
	ten[0] = 1;
	for(int i = 1; i <= 15; ++i){
		dp[i] = i * ten[i-1];
		ten[i] = 10 * ten[i-1];
	}
}
void solve(ll x, ll *cnt){
	int len = 0;
	while(x){
		num[++len] = x % 10;
		x /= 10;
	}
	for(int i = len; i >= 1; --i){
		for(int j = 0; j <= 9; ++j){
			cnt[j] += dp[i-1] * num[i];
		}
		for(int j = 0; j < num[i]; ++j){
			cnt[j] += ten[i-1];
		}
		ll num2 = 0;
		for(int j = i - 1; j >= 1; --j){
			num2 = 10 * num2 + num[j];
		}
		cnt[num[i]] +=  num2 + 1;
		cnt[0] -= ten[i-1];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b;
	cin  >>  a >> b;
	init();
	solve(a-1,cnta);
	solve(b,cntb);
	for(int i = 0; i <= 9; ++i){
		cout << cntb[i] - cnta[i] << ' ' ;
	}
	return 0;
}