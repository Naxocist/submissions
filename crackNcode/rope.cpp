#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
ll f(ll l, ll r) {
	ll n = r-l+1;
	return n*(n+1)/2;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, p; cin >> n >> p;
	ll x, y, z; cin >> x >> y >> z;
	multiset<ll> ms;
	vector<ll> cnt(5e5+3, 0), A(n), B(n);
	for(auto &x : A) cin >> x;
	for(auto &x : B) cin >> x;
	vector<pi> w;
	ll l, r, pt, res, ed = -1; res = l = r = pt = 0;
	for(; l<n; ++l) {
		for(;r<n;r++){
			ll a = A[r], b = B[r];
			if(pt + a > x) break ;
			if(y != -1 and ms.size()) {
				ll mx = *(--ms.end()), mn = *(ms.begin());
				if(a > mx and a - mn > y) break ;
				else if(a < mn and mx - a > y) break ; 
			}
			if(z != -1 and cnt[b] + 1 > z) break ; 
			pt += a;
			if(y != -1) ms.insert(a);
			if(z != -1) cnt[b] ++;
		}
		pt-=(ll)A[l];
		if(y != -1) ms.erase(ms.find(A[l]));
		if(z != -1) cnt[B[l]] -- ;
		
		res += f(l, r-1);
		if(l <= ed) res -= f(l, ed);
		ed = r-1;
	}

	cout << res;
	return 0;
}