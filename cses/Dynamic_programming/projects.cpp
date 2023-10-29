#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
using T = tuple<int, int, int>;
using pi = pair<int, int>;
 
 
int main() {
 
	int n; scanf("%d", &n);
 
	set<T> s; 
	
	for(int i=0; i<n; ++i) {
		int a, b, v; scanf("%d%d%d", &a, &b, &v);
		s.emplace(b, a, v);
	}
 
	ll res = 0;
	set<array<ll, 2>> dp;
	dp.insert({0, 0});
	for(auto e : s) {
		int a, b, v; tie(b, a, v) = e;
		auto t = dp.lower_bound({a});
		t--;
		res = max(res, (*t)[1] + v);
		dp.insert({b, res});
	} 
 
	printf("%lld", res);
	return 0;
}
