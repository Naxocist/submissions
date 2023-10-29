#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using pi = pair<int, int>;
using T = tuple<int, int, int, int>;
void f(pi &t) {
	cout << t.first << ' ' << t.second << '\n'; return ;
}

int main() {
	int x, y; cin >> x >> y;
	int n; cin >> n;
	vector<vector<pi>> v(4, vector<pi>(n));
	vector<T> A, C;
	for(int i=0; i<4; ++i) for(auto &x : v[i]) cin >> x.first >> x.second;
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			A.emplace_back(v[0][i].first + v[1][j].first, v[0][i].second + v[1][j].second, i, j);
			C.emplace_back(v[2][i].first + v[3][j].first, v[2][i].second + v[3][j].second, i, j);
		}
	}
	sort(all(A)); sort(all(C));
	for(auto t : A) {
		int x1, y1, i1, j1; tie(x1, y1, i1, j1) = t;
		int l = 0, r = n*n-1;
		while(l <= r) {
			int md = l + (r-l)/2;
			int x2, y2, i2, j2; tie(x2, y2, i2, j2) = C[md];
			if(x1 + x2 == x and y1 + y2 == y) {
				f(v[0][i1]), f(v[1][j1]), f(v[2][i2]), f(v[3][j2]); 
				return 0;
			}
			if(x1 + x2 > x) r = md - 1;
			else if(x1 + x2 < x) l = md + 1;
			else if(y1 + y2 > y) r = md - 1;
			else l = md + 1;
		}
	}
	return 0;
}