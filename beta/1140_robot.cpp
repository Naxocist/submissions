#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e3 + 3;
int dp[N][N];
vector<pi> ar[N];

int dist(pi a, pi b) {
	int x = a.first - b.first, y = a.second - b.second;
	return x*x + y*y;
}

int main() {

	int n, q; scanf("%d%d", &n, &q);

	vector<pi> v;
	int x, y;
	for(int i=0; i<n; ++i) {
		scanf("%d%d", &x, &y);
		v.emplace_back(x, y);
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			ar[i].emplace_back(dist(v[i], v[j]), j);
		}
	}

	for(int i=0; i<n; ++i) sort(ar[i].begin(), ar[i].end());

	for(int i=0; i<n; ++i) {
		bitset<N> vis;
		vis[i] = true;
		vector<int> order;
		order.push_back(i);

		int c = i;
		for(int j=0; j<n; ++j) {

			for(auto e : ar[c]) { // distance, point
				int x = e.second;
				if(vis[x]) continue ;
				c = x;
				vis[x] = true;
				order.push_back(x);
				break;
			}
			
		}

		for(int k=0; k<n; ++k) {
			dp[i][order[k]] = k + 1;
		}
	}


	while(q--) {
		int t; scanf("%d%d%d", &x, &y, &t); t--;
		int s = 0, mn = INT_MAX;
		for(int i=0; i<n; ++i) {
			int a, b; tie(a, b) = v[i];
			int d = dist(pi(x, y), pi(a, b));
			if(d < mn) {
				mn = d;	
				s = i;
			}
		}

		printf("%d\n", dp[s][t]);
	}

	return 0;
}