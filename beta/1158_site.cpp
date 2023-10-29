#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int s[N][N];

int main() {

	int n, m, k; scanf("%d%d%d", &n, &m, &k);

	int res = 0;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			scanf("%d", &s[i][j]);
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}


	for(int i=1; i<=n-k+1; ++i) {
		for(int j=1; j<=m-k+1; ++j) {
			int r = i + k - 1, c = j + k - 1;
			res = max(res, s[r][c] - s[i-1][c] - s[r][j-1] + s[i-1][j-1]);
		}
	}	
	printf("%d", res);
	return 0;
}