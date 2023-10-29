#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vector<int> v(n+1), idx(n+1);
	for(int i=1; i<=n; ++i) {
		cin >> v[i], idx[v[i]] = i;
	}
 
	int k = INT_MAX, res = 0;
	for(int i=1; i<=n; ++i) {
		if(idx[i] < k) res ++;
		k = idx[i];
	}
 
	while(q--) {
		int x, y; cin >> x >> y;
		int nx = v[x], ny = v[y];
		if(idx[nx-1] <= idx[nx] and idx[nx-1] > y) res ++;
		if(idx[nx-1] > idx[nx] and idx[nx-1] <= y) res --;
		if(idx[nx] <= idx[nx+1] and y > idx[nx+1]) res ++;
		if(idx[nx] > idx[nx+1] and y <= idx[nx+1]) res --;
		idx[nx] = y;
 
		if(idx[ny-1] <= idx[ny] and idx[ny-1] > x) res ++;
		if(idx[ny-1] > idx[ny] and idx[ny-1] <= x) res --;
		if(idx[ny] <= idx[ny+1] and x > idx[ny+1]) res ++;
		if(idx[ny] > idx[ny+1] and x <= idx[ny+1]) res --;
		idx[ny] = x;
		swap(v[x], v[y]);
		cout << res << '\n';
	}
 
	return 0;
}