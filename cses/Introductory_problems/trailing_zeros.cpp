#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
 
int main() {
	
	ll n; scanf("%lld", &n);
 
	ll cnt=0;
	for(int i=5; n/i >= 1; i*=5){
		cnt += n/i;
	}
	printf("%lld", cnt);
	return 0;
}