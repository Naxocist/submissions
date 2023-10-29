#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 3;
using pi = pair<int, int>;
bool vis[N][N];
int path[N][N];
int t[] = {1, 0, -1, 0, 1};
string mv = "DLUR";
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
 
	int x, y;
	queue<pi> q;
 
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			char c; cin >> c;
			path[i][j] = -1;
			if(c == '#') vis[i][j] = 1;
			if(c == 'A') q.emplace(i, j), vis[i][j] = 1;
			if(c == 'B') x = i, y = j;
		}
	}
 
 
	while(q.size()) {
		 int i, j; tie(i, j) = q.front(); q.pop();
		 if(i == x && j == y) break ;
 
		 for(int k=0; k<4; ++k) {
		 	int ii = i + t[k], jj = j + t[k+1];
		 	if(ii < 1 || jj < 1 || ii > n || jj > m || vis[ii][jj]) continue ;
		 	path[ii][jj] = k;
		 	vis[ii][jj] = 1;
		 	q.emplace(ii, jj);
		 }
	}
 
	if(vis[x][y]) {
		cout << "YES\n";
		int p = path[x][y];
		string res;
		while(p != -1) {
			res += mv[p];
			if(p == 0) x--;
			else if(p == 1) y++;
			else if(p == 2) x++;
			else y--;
			p = path[x][y];
		}
		reverse(res.begin(), res.end());
		cout << res.size() << '\n' << res;
 
	} else  cout << "NO";
	return 0;
}
