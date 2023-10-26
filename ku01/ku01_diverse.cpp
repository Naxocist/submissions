#include <bits/stdc++.h>
using namespace std;
const int N = 53;
int ar[N][N];

bool f(int a, int b) {
	int cnt[10] = {0}, res = 0;
	for(int i=a; i<a+5; ++i) {
		for(int j=b; j<b+5; ++j) {
			if(cnt[ar[i][j]]++) continue ;
			res ++;
		}
	}

	return res >= 5;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> ar[i][j];
		}
	}

	if(n < 5 || m < 5) {
		cout << 0; return 0;
	}
	int res = 0;
	for(int i=1; i<=n-4; ++i) {
		for(int j=1; j<=m-4; ++j) {
			res += f(i, j);
		}
	}
	cout << res;
	return 0;
}