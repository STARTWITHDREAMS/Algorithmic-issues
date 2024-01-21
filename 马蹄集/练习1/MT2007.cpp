#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int N = 2e5+5;
int dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string>q;
	string x;
	while(cin >> x){
		if(x == ".")
			break;
		q.insert(x);
	}
	string s, tp;
	while(cin >> tp)
		s = s + tp;
	int n = s.size();
	s = ' ' + s;
	dp[0] = 1;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		string tmp = "";
		for(int j = i; j >= max(1, i - 10); --j){
			tmp = s[j] + tmp;
			if(dp[j-1] && q.count(tmp)){
				dp[i] = 1;
				break;
			}
		} 
		if(dp[i] == 1){
			ans =  max(ans, i);
		}
	}
	cout << ans;
	return 0;
}