#include <bits/stdc++.h>
using namespace std;

bool ar[103][43];

vector<int> path;
int n, k, t;

void dfs(int r, int c) {
	
	// printf("%d %d\n", r, c);
	if(r == t) {
		for(int x : path) printf("%d\n", x);
		return ;
	}

	if(ar[r+1][c]) {
		path.push_back(3);
		dfs(r+1, c);
		path.pop_back();
	}
	if(ar[r+1][c+1]) {
		path.push_back(2);
		dfs(r+1, c+1);
		path.pop_back();
	}
	if(ar[r+1][c-1]) {
		path.push_back(1);
		dfs(r+1, c-1);
		path.pop_back();
	}
}

int main() {

	scanf("%d%d%d", &n, &k, &t);

	for(int i=1; i<=t; ++i) {
		for(int j=1; j<=n; ++j) {
			int x; scanf("%d", &x);
			if(x == 0) ar[i][j] = true;
		}
	}

	dfs(0, k);
	return 0;
}