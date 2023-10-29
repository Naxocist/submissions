#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 11;
ll mod = 1e9, n;

struct mat {
	ll m[N][N] = {0};

	mat operator*(mat &other) {
		mat res;
		for(int i=1; i<N; ++i) {
			for(int j=1; j<N; ++j) {
				for(int k=1; k<N; ++k) {
					res.m[i][j] += (m[i][k]*other.m[k][j])%mod;
					res.m[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

void f() {
	int k; cin >> k;
	mat res, t;
	for(int i=1; i<=k; ++i) cin >> res.m[i][1];
	for(int i=1; i<k; ++i)  t.m[i][i+1] = 1;
	for(int j=k; j>=1; --j) cin >> t.m[k][j];

	int n; cin >> n;
	if(n <= k) {
		cout << res.m[n][1] << '\n';
		return ;
	}
	n -= k;
	mat r;
	for(int i=1; i<=k; ++i) r.m[i][i] = 1;
	for(; n; n>>=1, t = t*t) if(n&1) r = r*t;
	r = r * res;
	cout << r.m[k][1] << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) f();
	return 0;
}

/*
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

3 
3 
5 8 2 
32 54 6 
2 
*/