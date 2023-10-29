#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;

	vector<int> v(m);
	for(int &x : v) cin >> x;

	int x; cin >> x;
	
	int cnt = 0;
	for(auto y : v) {
		int t = k;
		for(int i=0; i<n; ++i) {
			if(((1<<i)&y) != ((1<<i)&x)) t--;
		}

		cnt += t>=0;
	}

	cout << cnt;
	return 0;
}