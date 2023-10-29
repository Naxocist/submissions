#include <bits/stdc++.h>
using namespace std;

const int N = 5003;
int qs[N][N];
int n, m, r, c;

int qry(int i, int j, int ni, int nj) {
	ni = min(ni, r), nj = min(nj, c); i = max(1, i), j = max(1, j);

	return qs[ni][nj] - qs[i-1][nj] - qs[ni][j-1] + qs[i-1][j-1];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> r >> c;

	using T = tuple<int, int, int>;
	vector<T> t(n);
	for(auto &x : t) {
		int a, b, c; cin >> a >> b >> c;
		x = T(a, b, c);
	}

	while(m--) {
		int x, y; cin >> x >> y;
		qs[x][y]++;
	}
	for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) 
		qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];


	int sz = 0;
	for(auto &x : t) {
		int a, b, c; tie(a, b, c) = x;
		while(qry(a-sz, b-sz, a+sz, b+sz) < c) sz++;
	}

	cout << sz;
	return 0;
}