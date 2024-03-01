#include<bits/stdc++.h>
using namespace std;
int a[25];
int main(){
	int n = 1, k = 1, m = 1;
	while(n != 0 || k != 0 || m != 0){
		scanf(" %d %d %d", &n, &k, &m);
		vector<int>q(n);
		iota(q.begin(), q.end(),1);
		memset(a, 0, sizeof a);
		int ta = 0, tb = n-1;
		int tmp = n;
		while(n > 0){
			int nk = k, nm = m;
			while(nk - 1){
				ta = (ta + 1) % tmp;
				if(a[ta]){
					continue;
				}
				nk--;
			}
			while(nm - 1){
				tb = (tb - 1 + tmp) % tmp;
				if(a[tb]){
					continue;
				}
				nm--;
			}
			if(ta == tb){
				a[ta] = 1;
				n--;
				if(n == 0){
					printf("%3d\n", q[ta]);
					break;
				}
				else{
					printf("%3d,", q[ta]);
					ta = (ta + 1) % tmp;
					while(a[ta]){
						ta = (ta + 1) % tmp;
					}
					tb = (tb - 1 + tmp) % tmp; 
						while(a[tb]){
						tb = (tb - 1 + tmp) % tmp; 
					}
				}
			}else{
				n = n - 2;
				a[ta] = a[tb] = 1;
				if(n == 0){
					printf("%3d%3d\n", q[ta], q[tb]);
					break;
				}else{
					printf("%3d%3d,", q[ta], q[tb]);
					ta = (ta + 1) % tmp;
					while(a[ta]){
						ta = (ta + 1) % tmp;
					}
					tb = (tb - 1 + tmp) % tmp; 
					while(a[tb]){
						tb = (tb - 1 + tmp) % tmp; 
					}
				}
			} 
		}
	}
	return 0;
}