#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1e5;
int seg[4*N], ar[N], L, R, M;
bool lzy[3][4*N];
char c; 

void f(int t, int i, int l, int r) {
	if(t == 0) {
		seg[i] = 0;
	}else if(t == 1) {
		seg[i] = r - l + 1;
	}else {
		seg[i] = r - l + 1 - seg[i];
		if(l != r) lzy[t][2*i] = !lzy[t][2*i], lzy[t][2*i+1] = !lzy[t][2*i+1];
	}
	lzy[t][i] = 0; 
	if(l != r and t != 2) lzy[t][2*i] = lzy[t][2*i+1] = 1;
}

void build(int i, int l, int r) {
	if(l == r) {
		seg[i] = ar[l]; return ;
	}
	int md = l + (r-l)/2;
	build(2*i, l, md); build(2*i+1, md+1, r);

	seg[i] = seg[2*i] + seg[2*i+1];
	return ;
}

int qry(int i, int l, int r) {
	for(int j=0; j<3; ++j) if(lzy[j]) f(j, i, l, r);
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return seg[i];
	
	int md = l + (r-l)/2;

	return qry(2*i, l, md) + qry(2*i+1, md+1, r);
}

void upd(int i, int l, int r) {
	for(int j=0; j<3; ++j) if(lzy[j]) f(j, i, l, r);
	if(r < L || R < l) return ;
	if(L <= l && r <= R) {
		if(c == 'E') f(0, i, l, r);
		else if(c == 'F') f(1, i, l, r);
		else f(2, i, l, r);
		return ;
	}
	int md = l + (r-l)/2;
	upd(2*i, l, md); upd(2*i+1, md+1, r);
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;

	int k = 1;
	while(n--) {
		int t; cin >> t; 
		string s; cin >> s;
		while(t--)
		for(char c : s) {
			int x = c - '0';
			ar[k++] = x;
		}
	}	
	n = k-1;

	build(1, 1, n);

	int q; cin >> q;
	while(q--) {
		cin >> c >> L >> R, L++, R++;

		if(c == 'F') {
			
		}else if(c == 'E') {
			
		}else if(c == 'I') {
			
		}else {
			cout <<  qry(1, 1, n) << '\n';
		}
	}
	return 0;
}