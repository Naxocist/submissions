#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;
	set<int> s;
	for(int i=0; i<n; ++i) {
		int t=0;
		for(int j=i; j<n; ++j) {
			t += v[j];
			s.insert(t);
		}
	}
	cout << s.size();
	return 0;	
}