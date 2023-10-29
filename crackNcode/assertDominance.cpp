#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;
int l[N][N], r[N][N], b[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			char c; cin >> c;
			l[i][j] = r[i][j] = b[i][j] = (c == 'X');
		}
	}
		

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j) if(l[i][j]) l[i][j] += l[i][j-1];
		for(int j=m; j>=1; --j) if(r[i][j]) r[i][j] += r[i][j+1];
	}

	for(int i=n; i>=1; --i) 
		for(int j=1; j<=m; ++j) if(b[i][j]) b[i][j] += b[i+1][j];
	
	int res = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			int k = min(min(l[i][j], r[i][j])*2 - 1, b[i][j]);
			if(k&1^1) k--;
			res = max(res, k);
		}
	}

	cout << res;
	return 0;
}