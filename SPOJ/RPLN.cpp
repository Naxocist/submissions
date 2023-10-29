#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, t; scanf("%d%d", &n, &t);
	
	vector<vector<int>> sp(n+1, vector<int>(log2(n)+10, 0));

	for(int i=1; i<=n; ++i) scanf("%d", &sp[i][0]);
	for(int j=1; (1<<j)<=n; ++j) {
		for(int i=1; i+(1<<j)-1<=n;++i) {
			sp[i][j] = min(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
		}
	}

	while(t--) {
		int l, r; scanf("%d%d", &l, &r);
		int lg = log2(r-l+1);
		printf("%d\n", min(sp[l][lg], sp[r-(1<<lg)+1][lg])); 
	}
}
int main() {
	int q; scanf("%d", &q);
	for(int i=1; i<=q; ++i) {
		printf("Scenario #%d:\n", i);
		solve();
	}
	return 0;
}