#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define int long long
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n);
	int l = INF, r = 0;
	for(auto &x : v) cin >> x, l = min(l, x), r += x;
	int res = l;
	while(l <= r) {
		int md = l + (r-l)/2;
		int s = 0, shop = 0;
		priority_queue<int> pq;
		for(auto x : v) {
			s += x;
			pq.emplace(-x);
			if(pq.size() > k) s -= -pq.top(), pq.pop();

			if(s >= md and pq.size() == k) {
				s = 0;
				shop++;
				while(pq.size()) pq.pop();
			}
		}
		if(shop >= m) l = md + 1, res = md;
		else r = md - 1;
	}	
	cout << res;
	return 0;
}