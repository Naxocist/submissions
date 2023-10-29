#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 3;
using T = tuple<int, int, bool>;
int vis[N][N];
int t[] = {1, 0, -1, 0, 1}, path[N][N];
string mv = "DLUR";
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
 
	queue<T> q;
 
	int g = 0, h = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			path[i][j] = -1;
			vis[i][j] = 1e9;
			char c; scanf(" %c", &c);
			if(c == '#') vis[i][j] = -1;
			if(c == 'A') g = i, h = j;
			if(c == 'M') q.emplace(i, j, false), vis[i][j] = 0;
		}
	}
 
	q.emplace(g, h, true); vis[g][h] = 0;;
 
	while(q.size()) {
		int x, y; bool p; tie(x, y, p) = q.front(); q.pop(); 
 
		if((x == 0 || y == 0 || x == n-1 || y == m-1) && p) {
			printf("YES\n");
			int p = path[x][y];
			string s;
			while(p != -1) {
				s += mv[p];
				if(p == 0) x--;
				else if(p == 1) y++;
				else if(p == 2) x++;
				else y--;
				p = path[x][y];
			}
			reverse(s.begin(), s.end());
			printf("%d\n%s", s.size(), s.c_str());
			return 0;
		}
 
		for(int i=0; i<4; ++i) {
			int xx = x + t[i], yy = y + t[i+1];
			if(xx < 0 || yy < 0 || xx >= n || yy >= m || vis[x][y] + 1 >= vis[xx][yy]) 
				continue ;
			if(p) {
				path[xx][yy] = i;
			}
			vis[xx][yy] = vis[x][y] + 1;
			q.emplace(xx, yy, p);
		}
	}
 
	printf("NO");
	return 0;
}
