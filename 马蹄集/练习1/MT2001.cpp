#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int N = 1e5+5;
vector<int>q;
vector<int>p;
int vis[N];
int solve(int x){
	int sum = 0;
	while(x){
		sum += x % 10;
		x/=10;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		if(solve(x) % 3 != 0){
			q.pb(x);
			p.pb(solve(x));
		}
	}
	int s2 = (n - q.size())/2;
	int len = p.size();
	int s1 = 0;
	for(int i = 0; i < len; ++i){
		for(int j = i+1; j < len; ++j){
			if(!vis[i] && !vis[j] && (p[i] + p[j]) % 3 == 0){
				s1++;
				vis[i] = 1;
				vis[j] = 1;
			}
		}
	}
	cout << s1 + s2;
	return 0;
}