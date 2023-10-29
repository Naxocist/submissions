#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;
using pi = pair<int, int>;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<T> v(n);
	for(int i=0; i<n; ++i) {
		int x, y; cin >> x >> y;
		v[i] = T(x, y, i);
	}
	sort(v.begin(), v.end());
 
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	vector<int> res(n);
	int r = 1;
	pq.emplace(-1, r);
	for(int i=0; i<n; ++i) {
		int x, y, j; tie(x, y, j) = v[i];
		
		int ed, rm; tie(ed, rm) = pq.top();
		if(ed < x) {
			pq.pop();
			pq.emplace(y, rm);
			res[j] = rm;
		}else {
			pq.emplace(y, ++r);
			res[j] = r;
		}
	}
 
	cout << r << '\n';
	for(auto x : res) cout << x << ' ';
	return 0;
}
