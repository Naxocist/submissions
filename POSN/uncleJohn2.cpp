#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int seg[4*N];
bool lazy[4*N];
int L, R;

void f(int i, int l, int r) {
	seg[i] = (r-l+1)-seg[i]; 
	lazy[i] = false;
	if(l!=r){
		lazy[2*i] = !lazy[2*i], lazy[2*i+1] = !lazy[2*i+1];
	}
	return ;
}

int sum(int i, int l, int r) {
	if(lazy[i]) f(i, l, r);

	if(L <= l && r <= R) {
		return seg[i];
	}
	if(r < L || R < l) return 0;
	int md = l + (r-l)/2;

	int s = sum(2*i, l, md) + sum(2*i+1, md+1, r);
	seg[i] = seg[2*i] + seg[2*i+1];
	return s;
}

void upd(int i, int l, int r) {
	if(lazy[i]) f(i, l, r);
	
	if(L <= l && r <= R) {
		f(i, l, r);
		return ;
	}
	if(r < L || R < l) return ;
	int md = l + (r-l)/2;
	upd(2*i, l, md); upd(2*i+1, md+1, r);
	seg[i] = seg[2*i] + seg[2*i+1];
	return ;
}

int main() {

	int n, q; cin >> n >> q;
	while(q--) {
		int c; cin >> c >> L >> R;
		if(c) cout << sum(1, 1, n) << '\n';
		else upd(1, 1, n);
	}

	return 0;
}