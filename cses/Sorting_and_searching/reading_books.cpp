#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 
	int n; scanf("%d", &n);
	ll s = 0, mx = 0;
	while(n--) {
		ll x; scanf("%lld", &x);
		s += x, mx = max(mx, x);
	}
	printf("%lld", max(s, mx*2));
 
	return 0;
}
