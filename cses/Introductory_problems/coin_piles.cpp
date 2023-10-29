#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
 
int main() {
	
	int t; scanf("%d", &t);
 
	while(t--){
		ll a, b; scanf("%lld %lld", &a, &b);
		if(a < b) swap(a, b);
 
		if(a > 2*b){
			printf("NO\n");
			continue;
		}
 
		a %= 3; b %= 3;
		if(a > b) swap(a, b);
		if((a == 1 && b == 2) || (a == b && a == 0)) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}