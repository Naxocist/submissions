#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
 
int main() {
	
	int n; scanf("%d", &n);
	long long k, possible, dup;
	for(int i=1; i<=n; ++i){
		k = i*i;
		possible = k*(k-1)/2;
		dup = 4 * (i-1) * (i-2);
		printf("%lld\n", possible - dup);
	}
	
	return 0;
}
