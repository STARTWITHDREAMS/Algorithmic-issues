#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int N = 1e5+5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0;
	bool st = 0;
	ll cnt = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			cnt++;
			st = 1;
		}else if(st == 1){
			ans += cnt*(cnt+1)/2;
			st = 0;
			cnt = 0;
		}else{
			cnt = 0;
		}
	}
	if(st)
		ans += cnt*(cnt+1)/2;
	cout << ans;
	return 0;
}