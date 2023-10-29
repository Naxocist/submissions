#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q = 4;
	while(q--) {
		string s; cin >> s;
		for(auto &x : s) x = tolower(x);
		unordered_set<string> seen;

		for(int i=0; i<s.size(); ++i) {
			string t;
			for(int j=i; j<s.size(); ++j) {
				t += s[j];
				if(seen.find(t) != seen.end()) continue ;
				seen.insert(t);
				mp[t] ++;
			}
		}
	}
	int res = 0; string r;
	for(auto e : mp) {
		string s; int c; tie(s, c) = e; 
		int n = s.size();
		if(c >= 3 && n > res || (n == res && s < r)) {
			res = n;
			r = s;
		}
	}
	cout << r;
	return 0;
}