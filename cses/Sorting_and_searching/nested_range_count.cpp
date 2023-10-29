#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3;
int fw[2*N], res[2][N];
map<int, int> mp;
 
int qry(int i) {
	int s = 0;
	for(;i; i-=i&-i) s += fw[i];
	return s;
}
 
void upd(int i, int x) {
	for(;i<2*N;i+=i&-i) fw[i] += x;
}
 
struct T {
	int l, r, d;
};
 
bool cmp(T x, T y) {
	if(x.l == y.l) return x.r > y.r;
	return x.l < y.l;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	set<int> s;
	T v[n+1];
	for(int i=1; i<=n; ++i) {
		int l, r; cin >> l >> r;
		v[i] = {l, r, i};
		s.insert(l), s.insert(r);
	}
	int u = 1;
	for(auto e : s) mp[e] = u++;
 
	sort(v+1, v+1+n, cmp);
	
	for(int i=n; i>=1; --i) {
		int r = mp[v[i].r], d = v[i].d;
		res[0][d] = qry(r);
		upd(r, 1);
	}
	memset(fw, 0, sizeof fw);
	for(int i=1; i<=n; ++i) {
		int r = mp[v[i].r], d = v[i].d;
		res[1][d] = (i-1) - qry(r-1);
		upd(r, 1);
	}
 
	for(int i=0; i<2; ++i){
		for(int j=1; j<=n; ++j) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
