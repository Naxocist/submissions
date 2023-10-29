#include <bits/stdc++.h>
using namespace std;
const int N = 55;
using T = tuple<int, int, int>;
int ar[N][N], dist[N][N], n, m;
int tx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int ty[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int c = 1;
	while(1) {
		cin >> n >> m;
		if(!n && !m) break ;
		queue<T> q;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				char t; cin >> t;
				ar[i][j] = t - 'A' + 1;
				if(t == 'A') q.emplace(i, j, 1);
				dist[i][j] = 0;
			}
		}

		int mx = 0;
		while(q.size()) {
			int x, y, d; tie(x, y, d) = q.front(); q.pop();
			if(dist[x][y] >= d) continue ;
			dist[x][y] = d;
			mx = max(mx, d);
			int tx[] = {1, 1, 1, 0, 0, -1, -1, -1};
			int ty[] = {-1, 0, 1, -1, 1, -1, 0, 1};
			// cout << x << ' ' << y << ' ' << d << '\n';
			for(int i=0; i<8; ++i) {
				int xx = x + tx[i], yy = y + ty[i];
				if(xx < 1 || yy < 1 || xx > n || yy > m || ar[xx][yy] != ar[x][y]+1) continue ;
				q.emplace(xx, yy, d+1);
			}
		}
		cout << "Case " << c++ << ": " << mx << '\n';
	}
	return 0;
}