#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int ar[N], mem[N], cnt[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, q, x, y; cin >> n >> k >> q;
	for(int i=1; i<=n; ++i) cin >> ar[i], mem[i] = 1e9;
	int r = 1, sz = 0;
	for(int l=1; l<=n; ++l) {
		for(;sz<k and r<=n;++r) if(ar[r]<=k and ++cnt[ar[r]]==1) sz++;
		if(sz == k) mem[l] = r-1;
		if(ar[l]<=k and !--cnt[ar[l]]) sz--;
	}
	while(q--) cin >> x >> y, cout << (y >= mem[x] ? "YES" : "NO") << '\n';
	return 0;
}