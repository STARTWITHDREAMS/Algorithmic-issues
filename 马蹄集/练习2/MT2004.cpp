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
	int k = 0;
	while(s[k] == '0'){
		k++;
	}
	s = s.substr(k);
	int n = s.size();
	for(int i = 0; i < n/2; ++i){
		if(s[i] < s[n - i - 1]){
			s[n-i-1] = s[i];
		}else if(s[i] > s[n - i - 1]){
			int j = n-i-2;
			while(s[j] == '0'&& j >= i){
				s[j] = '9';
				j--;
			}
			s[j] = char(s[j]-1);
			if(j == 0 && s[j] == '0')
				s[n-i-1] = '9';
			else
				s[n-i-1] = s[i];
		}
	}
	k = 0;
	while(s[k] == '0'){
		k++;
	}
	s = s.substr(k);
	cout << s;
	return 0;
}