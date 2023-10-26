#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, res=0; cin >> n >> m >> k;
	vector<int> v;
	int p; cin >> p;
	for(int i=0; i<m-1; ++i){
		int x; cin >> x;
		v.emplace_back(x-p-1);
		p = x;
	}

	sort(v.begin(), v.end());
	for(int i=0; i<m-k; ++i) res += v[i];
	cout << res;
	return 0;
}