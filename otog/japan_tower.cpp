#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
const int N = 1e5 + 3;
vector<int> st[4*N];
int ar[N], L, R, v, idx, t;

void build(int i, int l, int r) {
	if(l == r) {
		st[i].push_back(ar[l]);
		return ;
	}
	int md = l+(r-l)/2;
	build(2*i, l, md); build(2*i+1, md+1, r);
	merge(all(st[2*i]), all(st[2*i+1]), back_inserter(st[i]));
}

int qry(int i, int l, int r) {
	if(r < L || l > R) return 0;
	if(L <= l and r <= R) {
		return upper_bound(st[i].begin(), st[i].end(), v) - st[i].begin();
	}
	int md = l+(r-l)/2;
	return qry(2*i, l, md) + qry(2*i+1, md+1, r);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> ar[i];

	build(1, 1, n);
	for(int i=1; i<=n; ++i) {
		L = 0, R = i-1, v = ar[i];
		cout << qry(1, 1, n) << ' ';
	}
	return 0;
}