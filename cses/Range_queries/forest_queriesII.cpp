#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int fw[N][N], ar[N][N], n, m;
 
int qry(int i, int ii) {
	int s = 0;
	for(;i>0;i-=i&-i) {
		for(int j=ii;j>0;j-=j&-j) s += fw[i][j];
	}
	return s;
}
 
void upd(int i, int ii) {
	int s = (ar[i][ii] ? -1 : 1);
	ar[i][ii] = !ar[i][ii];
	for(;i<=n;i+=i&-i) {
		for(int j=ii;j<=n;j+=j&-j) fw[i][j] += s;
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
 
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			char c; cin >> c;
			if(c == '*') upd(i, j); 
		}
	}
 
	while(m--) {
		int x, a, b, c, d; cin >> x;
		if(x == 1) cin >> a >> b, upd(a, b);
		else {
			cin >> a >> b >> c >> d;
			cout << qry(c, d) - qry(a-1, d) - qry(c, b-1) + qry(a-1, b-1) << '\n';
		}
	}
	return 0;
}