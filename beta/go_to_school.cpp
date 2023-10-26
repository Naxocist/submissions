#include <bits/stdc++.h>

using namespace std;

#define ll long long

using pi = pair<int, int>;

const int N = 55;

int r, c;

ll memo[N][N];

bool d[N][N];

int main() {

	ios::sync_with_stdio(false); cin.tie(nullptr);
    
	cin >> c >> r;

	int t; cin >> t;

	while(t--) {
		int y, x; cin >> y >> x;
		d[x][y] = 1;
	}

	memo[1][0] = 1;

	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(!d[i][j]) memo[i][j] = memo[i-1][j] + memo[i][j-1];
		}
	}

	cout << memo[r][c];

	return 0;

}