#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int N = 1e5+5;
map<string,int>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	int maxn = 0;
	for(int i = 0;  i < n-1; ++i){
		string tmp = s.substr(i,2);
		mp[tmp]++;
	}
	for(auto it : mp){
		if(it.se > maxn){
			ans = it.ff;
			maxn = it.se;
		}
	}
	cout << ans;
	return 0;
}