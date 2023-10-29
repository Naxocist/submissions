#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<string, int> cnt;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m; cin >> n >> m;
	string s; cin >> s;

	int l = 1, r = n, res = 0;
	while(l <= r) {
		int md = l + (r-l)/2, mx = 0;
		for(int i=0; i<=n-md+1; ++i) {
			mx = max(mx, ++cnt[s.substr(i, md)]);
			if(mx >= m) break ;
		}
		if(mx >= m) res = md, l = md + 1;
		else r = md - 1;
		cnt.clear();
	}
	cout << res;
	return 0;
}