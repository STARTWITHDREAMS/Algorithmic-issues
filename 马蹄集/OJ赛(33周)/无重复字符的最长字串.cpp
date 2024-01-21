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
	string s;
	getline(cin, s);
	int n = s.size();
	int p1 = -1, len = 0, p2 = 0, ans = 0;
	while(p2 < n){
		while(a[s[p2]]){
			a[s[++p1]] = 0;
			len--;
		}
		a[s[p2++]] = 1;
		len++;
		ans = max(ans, len);
	} 
	cout << ans;
	return 0;
}