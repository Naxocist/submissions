#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;

	int m; cin >> m;
	vector<int> b(m);
	for(auto &x : b) cin >> x;
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	int cnt = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(abs(a[i] - b[j]) <= 1) {
				cnt++, b[j] = -1; break ;
			}
		}
	}
	cout << cnt;
}