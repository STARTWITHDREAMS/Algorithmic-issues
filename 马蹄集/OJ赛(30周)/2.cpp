#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int n;
ll ans = 1e18;
vector<ll>q;
void dfs(int cnt1, int cnt2, ll sum){
	if(cnt1 > 5 || cnt2 > 5)
		return;
	if(sum && cnt1 == cnt2 && sum >= n)
		q.pb(sum);
	dfs(cnt1+1, cnt2, sum * 10 + 4);
	dfs(cnt1, cnt2 + 1,sum * 10 + 7);	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	dfs(0,0,0);
	for(auto it : q){
		ans = min(it, ans);
	}
	cout << ans;
	return 0;
}