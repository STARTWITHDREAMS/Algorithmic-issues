#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
ll cnt;
void dfs(int m, int n, ll sum){
	if(sum < 0 || sum == 0 && (m > 0|| n > 0))
		return;
	if(m == 0 && n == 0 && sum > 0)
		return;
	if(m == 0 && n == 0 && sum == 0){
		cnt++;
		return;
	}
	if(m > 0)
		dfs(m-1, n, sum * 2);
	if(n > 0)
		dfs(m, n-1, sum-2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n;
	cin >> m >> n;
	dfs(m,n,5);
	cout << cnt;
	return 0;
}