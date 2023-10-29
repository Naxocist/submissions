#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3, mod = 1e9 + 7;
using ll = long long;
ll a[N], up[N], down[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	a[0] = up[2] = down[2] = 1;
	for(int i=1; i<=n; ++i) {
		a[i] += a[i-1] + up[i-1] + down[i-1], a[i]%=mod;
		if(i>=2) a[i] += a[i-2], a[i]%=mod;

		up[i] += down[i-1], up[i] %= mod;
		down[i] += up[i-1], down[i] %= mod;
		if(i > 2) up[i] += a[i-2], down[i] += a[i-2], up[i]%=mod, down[i]%=mod;

		// cout << a[i] << ' ' << up[i] << ' ' << down[i] << endl;
	}

	cout << a[n];
	return 0;
}