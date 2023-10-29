#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 15003, b = 26, mod = 1e9 + 7;
ll p[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	p[0] = 1;
	for(int i=1; i<N; ++i) p[i]=(p[i-1]*b)%mod;

	int n, m; cin >> n >> m;
	string s; cin >> s;

	int l = 1, r = n, res = 0;
	while(l <= r) {
		int md = l + (r-l)/2, mx = 0;
		unordered_map<ll, int> cnt;
		ll hsh = 0;
		for(int i=0; i<md-1; ++i) hsh += (s[i])*p[md-i-1], hsh%=mod;

		for(int i=md-1; i<n; ++i) {
			hsh += s[i], hsh%=mod;
			mx = max(mx, ++cnt[hsh]);
			hsh -= (s[i-md+1])*p[md-1], hsh+=mod, hsh%=mod;
			hsh *= p[1], hsh %= mod;
		}
		if(mx >= m) res = md, l = md + 1;
		else r = md - 1;
	}
	cout << res;
	return 0;
}