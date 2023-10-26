#include <bits/stdc++.h>
using namespace std;
#define INF 2e18

using ll = long long;
ll pro[40];

int main() {

	ll n, k, c; scanf("%lld%lld%lld", &n, &k, &c);

	pro[0] = c;
	for(int i=1;i<=40; ++i) pro[i] = INF;
	int mx = 0;
	while(k--){
		int a, b; scanf("%d%d", &a,&b);
		pro[a] = min(pro[a], (ll)b);
		mx = max(mx, a);
	}

	for(int i=1; i<=mx; ++i) {
		ll x = 2;
		for(int j=i-1; j>=0; --j, x *= 2) {
			pro[i] = min(pro[i], pro[j]*x);
		}
	}
	ll res = 0;
	for(int i=mx; i>=0 && n; --i) {
		ll k = (1 << i);
		res += pro[i]*(n/k);
		// printf("%d\n", n/k);
		n -= k*(n/k);
	}	

	printf("%lld", res);
	return 0;
}