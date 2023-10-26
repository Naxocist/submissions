#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> v(30);
	for(int i=0; i<26; ++i) {
		cin >> v[i];
	}

	bool ok = 1;
	int k; cin >> k;
	set<string> w;
	while(k--) {
		string s; cin >> s;
		string t;
		for(int i=0; i<s.size(); ++i) {
			t += v[s[i] - 'A'] + '0';
		}
		// cout << s << ' ' << t << endl;
		if(w.find(t) != w.end()) {
			ok = 0;
		}
		w.insert(t);
	}
	if(!ok) cout << "YES\n";
	else 
	cout << "NO\n";
}

int main() {
	int q; cin >> q;
	for(int i=1; i<=q; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}