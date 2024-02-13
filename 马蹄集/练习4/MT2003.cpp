#include<bits/stdc++.h>
using namespace std;
map<int, int>mp;
void init(){
	for(int i = 1; i * (i+1)/2 <= 1e9; ++i){
		mp[i*(i+1)/2] = 1;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	init();
	int flag = 0;
	for(int i = 1;i*(i+1)/2 <= n; ++i){
		if(mp[n-i*(i+1)/2]){
			flag = 1;
			break;
		}
	}
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}