#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;

	using pi = pair<int, int>;
	vector<pi> v(n);
	for(auto &x : v) cin >> x.first >> x.second;

	sort(v.rbegin(), v.rend());
	stack<pi> s;
	int c = 0;
	for(auto x : v) {
		if(x.second > c) {
			s.emplace(x); c = x.second;
		}
	}
	while(s.size()) {
		cout << s.top().first << ' ' << s.top().second << '\n'; s.pop();
	}
	return 0;
}