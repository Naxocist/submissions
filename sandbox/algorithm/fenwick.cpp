#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int fw[N];
int n;

void upd(int i, int x) {
	for(;i<=n; i+=i&-i) {
		fw[i] += x;
	}
}

int get(int i) {
	int s = 0;
	for(;i>0; i-=i&-i) {
		s += fw[i];
	}
	return s;
}

int main() {
	n = 10;
	// for(int i=1; i<=n; ++i) cout << fw[i] << ' ' ;
	upd(3, 3);
	upd(1, 1);
	for(int i=1; i<=n; ++i) {
		cout << get(i) << ' ';
	}
	cout << endl;
 	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		cout << get(t) << '\n';
	}

	return 0;
}