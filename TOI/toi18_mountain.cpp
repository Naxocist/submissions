#include <bits/stdc++.h>
using namespace std;

#define INF 2e18

const int N = 5e2 + 3;
using ll = long long;
using pi = pair<ll, ll>;
ll dp[N][N];
pi ar[N];

ll dist(pi a, pi b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {

	int n, m; scanf("%d%d", &n, &m);

	for(int i=1;i<= n; ++i ) {
		ll x, y; scanf("%lld %lld", &x, &y);
		ar[i] = pi(x, y);
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			dp[i][j] = INF;
		}
	}

	for(int i=1; i<=n; ++i) dp[1][i] = dist(ar[1], ar[i]);

	for(int x=2; x<=n; ++x) {
		for(int i=2; i<=n; ++i) {
			for(int k=2; k<n; ++k) {
				if(i == k) continue;
				ll mx = max(dp[x-1][k], dist(ar[k], ar[i]));
				dp[x][i] = min(mx,dp[x][i]);
			}
		}
	}

	ll res = 0;
	while(m--) {
		ll p; scanf("%lld", &p);

		int x;
		for(x=1; x<=n; ++x) {
			if(p >= dp[x][n]) break ;
		}

		res += x;
	}

	printf("%lld", res);

	return 0;
}

/*
5 2
0 1
2 2
3 6
6 6
9 10
10
15
*/