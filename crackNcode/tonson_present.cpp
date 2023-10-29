#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 3;
int cnt[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	while(n--) {
		int x; cin >> x;
		cnt[x] ++;
	}
	for(int i=N-3; i>=0; --i) cnt[i] += cnt[i+1];

	for(int i=1; i<=m; ++i) {
		ll res = 0;
		for(int j=i; j<=N-3; j+=i) res += (ll)cnt[j];
		cout << res << '\n';
	}
	return 0;
}