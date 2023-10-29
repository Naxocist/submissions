#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


void solve() {
	
	string s; cin >> s;
	int n = s.size();
	vector<int> range;
	char t = '*';
	int r = 0;

	for(char c : s) {
		if(c != t) {
			if(t != '*') range.push_back(r);
			t = c;
			r = 0;
		}
		r++;
	}
	range.push_back(r);
	int m = range.size();
	if(range.size() == 1) {
		cout << (n + 1)/2 << '\n';
	}else {
		if(s[0] == s[n-1]) range[0] += range[m-1], range[m-1] = 0;
		int res = 0;
		for(int x : range) {
			res += x/2;
		}
		cout << res << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q; cin >> q;
	for(int i=1; i<=q; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

/*
PRSSP
PRPSP

*/