#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll maxn = 1LL << 31;
int a[105];
int main(){
	int s, n;
	set<ll>q;
	scanf(" %d %d", &s, &n);
	for(int i = 1; i <= s; ++i){
		scanf(" %d", &a[i]);
		q.insert(a[i]);
	}
	while(q.size() <= n){
		for(auto it : q){
			for(int i = 1; i <= s; ++i){
				if(it * a[i] > maxn)
					break;
				q.insert(it * a[i]);
			}
		}
	}
	int cnt = 1;
	for(auto it : q){
		if(cnt == n){
			printf("%d", it);
		}
		cnt++;
	}
	return 0;
}