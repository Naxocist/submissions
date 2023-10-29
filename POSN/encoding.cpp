#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int ar[N][N];
int x, y;
void f(int i, int j, int n, int m) {
	if(i < 1 || j < 1 || i > x || j > y || n == 0 || m == 0) return ;

	int nn = (n+1)/2, mm = (m+1)/2;

	bool one = 0, zero = 0;
	for(int a=i; a<i+n; ++a) {
		for(int b=j; b<j+m; ++b) {
			if(ar[a][b] == 1) one = 1;
			if(ar[a][b] == 0) zero = 1;
		}
	}

	if(one && zero) {
		cout << 'D';
		f(i, j, nn, mm);
		f(i, j+mm, nn, m - mm);
		f(i+nn, j, n - nn, mm);
		f(i+nn, j+mm, n - nn, m - mm );
	}else if(one) {
		cout << 1;
	}else {
		cout << 0;
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> x >> y;

	for(int i=1; i<=x; ++i) {
		string s; cin >> s;
		for(int j=1; j<=y; ++j) {
			ar[i][j] = s[j-1] - '0';
		}
	}

	f(1, 1, x, y);
	return 0;
}