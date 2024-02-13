#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int N = 1e2+5;
int a[N];
int vis[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] > mx){
			mx = a[i];
		}
	}
	int ans = 0;
	int flag = 0;
	for(int i = 1; i <= mx; ++i){
		int flag = 0;
		memset(vis, 0, sizeof vis);
		for(int j = 1; j <= n; ++j){
			if(vis[a[j]%i]){
				flag = 1;
				break;
			}
			vis[a[j]%i] = 1;	
		}
		if(!flag){
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}