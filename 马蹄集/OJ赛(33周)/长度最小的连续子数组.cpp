#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	ll sum = a[1];
	int p1 = 0, p2 = 1, ans = maxn, len = 1;
	while(p2 <= n){
		if(sum >= m){
			ans = min(ans, len);
			sum-=a[++p1];
			len--;
		}else{
			sum+=a[++p2];
			len++;
		}
	}
	cout << (ans == maxn ? 0 : ans);
	return 0;
}