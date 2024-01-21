#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int k;
	cin >> s >> k;
	int p1 = 0, p2 = 0;
	int ans = 0, cnt = 0;
	while(p2 < s.size()){
		if(s[p2] == 'a' || s[p2] == 'e' || s[p2] == 'i' || s[p2] == 'o' || s[p2] == 'u')
			cnt++;
		if(p2 - p1 + 1 == k){
			ans = max(ans, cnt);
			if(s[p1] == 'a' || s[p1] == 'e' || s[p1] == 'i' || s[p1] == 'o' || s[p1] == 'u')
				cnt--;
			p1++;
		}
		p2++;
	}
	cout << ans;
	return 0;
}