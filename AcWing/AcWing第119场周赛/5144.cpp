#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define ff first
#define se second
#define pii pair<ll,ll>
const int maxn = 1e5+5;
string s1[25] = {"zero","ten", "twenty", "thirty" , "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string s2[25] = {"one", "two", "three","four", "five", "six","seven", "eight", "nine"};
string s3[25] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int a = n/10;
	int b = n % 10;
	if(b == 0)
		cout << s1[a] ;
	else if(a == 0)
		cout << s2[b-1];
	else if(a == 1)
		cout << s3[b-1];
	else
		cout << s1[a] << '-' << s2[b-1];
	return 0;
}