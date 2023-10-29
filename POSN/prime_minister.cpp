#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
using pi = pair<int, int>;
int mat[N][N], ten[5];
bool isprime[N];
bitset<N> vis;

int change(int u, int i, int j) {
	int v = ((u/ten[i-1]) % 10) * ten[i-1];
	return u - v + j*ten[i-1];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ten[0] = 1;
	for(int i=1; i<=4; ++i) ten[i] = ten[i-1] * 10;
	memset(isprime, 1, sizeof isprime);
	for(int i=2; i*i<N; ++i) {
		if(!isprime[i]) continue ;
		for(int j=i*i; j<N; j+=i) {
			isprime[j] = 0;
		}
	}
	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		if(!isprime[x] || !isprime[y]) {
			cout << "impossible\n"; 
			continue ;
		}
		if(mat[x][y] || x == y) {
			cout << mat[x][y] << '\n';
			continue ;
		}
		vis.reset();
		queue<pi> q; 
		q.emplace(x, 0);
		vis[x] = 1;
		while(q.size()) {
			int u, d; tie(u, d) = q.front(); q.pop();
			mat[x][u] = d;
			mat[u][x] = d;

			if(u == y) {
				cout << d << '\n'; 
				break;
			}
			for(int i=1; i<=4; ++i) {
				for(int j=0; j<=9; ++j) {
					if(i == 4 and !j) continue ;
					int t = change(u, i, j);
					if(!isprime[t] || vis[t]) continue ;
					vis[t] = 1;
					q.emplace(t, d+1);
				}
			}
		}
	}
	return 0;
}