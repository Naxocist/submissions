#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int fw[N], ar[N], n;

int qry(int i) {
	int s = 0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}
void upd(int i, int x) {
	for(;i<=n;i+=i&-i) fw[i] += x;
}
void f() {
	int q; cin >> n >> q;
	memset(fw, 0, sizeof fw);
	for(int i=1; i<=n; ++i) {
		cin >> ar[i]; upd(i, ar[i]);
	}
	while(q--) {
		int c, l, r; cin >> c;
		if(c == 1) {
			cin >> l, l++;
			cout << ar[l] << '\n';
			upd(l, -ar[l]); ar[l] = 0;
		}else if(c == 2) {
			cin >> l >> r, l++;
			upd(l, r); ar[l] += r;
		}else {
			cin >> l >> r, l++, r++;
			cout << qry(r) - qry(l-1) << '\n';
		}
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case " << i << ":\n";
		f();
	}
	return 0;
}