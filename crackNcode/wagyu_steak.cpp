#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using ll = long long;
using pi = pair<int, int>;
ll ar[N];
vector<pi> p;
int main() {

	int n, q; ll m; scanf("%d%lld%d", &n, &m, &q);

	for(int i=1; i<=n; ++i) {
		scanf("%lld", &ar[i]);
		ar[i] += ar[i-1];
	}

	for(int i=1; i<=n; ++i) {

		int t = lower_bound(ar+i, ar+n+1, m + ar[i-1]) - ar;
		if(t != n + 1 && ar[t] == m + ar[i-1]) {
			p.emplace_back(i, t);
		}
	}

	while(q--) {
		int l, r; scanf("%d%d", &l, &r);

		auto t = lower_bound(p.begin(), p.end(), pi(l, 0)) - p.begin();

		for(int i=t; i<p.size(); ++i) {
			if(p[i].second > r) continue ;
			printf("Yes\n"); goto g;
		}
		printf("No\n");
		g:;
	}
	
	return 0;
}