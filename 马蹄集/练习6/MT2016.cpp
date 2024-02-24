#include<bits/stdc++.h>
#define ll long long 
using namespace std;
priority_queue<ll, vector<ll>, less<ll>>q1;
priority_queue<ll, vector<ll>, greater<ll>>q2;
double find(){
	double ans = 0;
	if(q1.empty() && q2.empty())
		return 0;
	else if(q1.size() > q2.size()){
		ans = q1.top();		
	}else if(q1.size() < q2.size()){
		ans = q2.top();
	}else{
		ans = (double)(q1.top() + q2.top()) /2;
	}
	return ans;
}
void Insert(ll x){
	if(q1.empty() && q2.empty()){
		q1.push(x);
		return;
	}
	if(q1.size() > q2.size()){
		if(x >= q1.top()){
			q2.push(x);
		}else{
			ll t = q1.top();
			q1.pop();
			q2.push(t);
			q1.push(x);
		}
	}else if(q1.size() < q2.size()){
		if(x <= q2.top()){
			q1.push(x);
		}else{
			ll t = q2.top();
			q2.pop();
			q1.push(t);
			q2.push(x);
		}
	}else{
		if(x >= q1.top()){
			q2.push(x);
		}else{
			q1.push(x);
		}
	}
	return;
}
int main(){
	int n;
	scanf(" %d", &n);
	for(int i = 1; i <= n; ++i){
		char t; ll tt;
		scanf(" %c", &t);
			if(t == '+'){
				scanf(" %d", &tt);
				Insert(tt);
			}else{
				double ans = find();
				if(ans - (int)ans > 0.4)
					printf("%.1lf\n", ans);
				else
					printf("%lld\n", (ll)ans);
			}
	}
	return 0;
}