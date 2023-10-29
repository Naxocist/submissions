#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
 
int main() {
	int t; scanf("%d", &t);
 
	while(t--){
		long long y, x; scanf("%lld %lld", &y, &x);
 
		long long mx = max(y, x);
		
		if(mx%2 == 0){
			if(x == 1) 
				printf("%lld\n", mx*mx);
			else if(x > y) 
				printf("%lld\n", (mx*mx - x + 1) - mx + y);
			else 
				printf("%lld\n", mx*mx - x + 1);
		}else{
			if(y == 1) 
				printf("%lld\n", mx*mx);
 
			else if(x > y)
				printf("%lld\n", mx*mx - y + 1);
			else
				printf("%lld\n", (mx*mx - y + 1) - mx + x);
		}
	}
	
	return 0;
}
