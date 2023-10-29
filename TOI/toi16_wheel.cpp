#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 13;
int n, k;
ll lcm[N], res = LLONG_MAX;
string v[N];

void f(ll x, int l) {
	if(l == n + 1) {
		res = min(res, x);
		return ;
	}
	
	for(ll i=0; i<=lcm[l+1] and x+i < res; i+=lcm[l]) {
		if(v[l][(x+i)%v[l].size()] == k + '0') {
			f(x+i, l+1);
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	lcm[1] = 1;
	
	for(int i=1; i<=n; ++i) {
		cin >> v[i];
		lcm[i+1] = lcm[i] * v[i].size() / __gcd(lcm[i], (ll)v[i].size());
	}
	f(1, 1);
	cout << res;
	return 0;
}