#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, n;
	scanf(" %d %d %d", &a, &b, &n);
	int res = b - a;
	int flag = 0, ans = 0;
	for(int i = min(-res, res); i <= max(-res, res); ++i){
		int tmp = 1; 
		for(int j = 1; j <= n; ++j){
			tmp *= i;
			if(abs(tmp) > abs(res))
				break;
		}
		if(tmp == res){
			flag = 1;
			ans = i;
			break;
		}
	}
	if(flag){
		printf("%d", ans);
	}else{
		printf("No solution");
	}
	return 0;
}