#include <bits/stdc++.h>
using namespace std;
const int N = 10, n = 8;
bool no[N][N];
bool c[N], d1[2*N], d2[2*N], t[N][N];
int res = 0;
void f(int i, int q) {
	if(q == 0) {
		res ++; return ;
	}
 
	for(int j=1; j<=n; ++j) {
		if(c[j] || d1[i + j] || d2[n-i+1+j] || no[i][j]) continue ;
		
		c[j] = d1[i + j] = d2[n-i+1+j] = 1;
		f(i+1, q-1);
		c[j] = d1[i + j] = d2[n-i+1+j] = 0;
	}
 
}
int main() {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			char c; cin >> c;
			if(c == '*') no[i][j] = 1;
		}
	}
 
	f(1, 8);
	cout << res;
	return 0;
}
