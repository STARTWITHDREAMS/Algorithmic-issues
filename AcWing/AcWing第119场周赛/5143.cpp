#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
void solve(){
	string s, ans;
	cin  >> s;
	for(int i  = 0; i < s.size(); i+=2){
		ans += s[i];
	}
	ans += s[s.size()-1];
	cout << ans << '\n';
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