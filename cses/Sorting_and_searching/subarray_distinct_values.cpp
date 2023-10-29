#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, t; cin >> n >> t;
	vector<int> v(n+1); for(int i=1; i<=n; ++i) cin >> v[i];
	
	int d = 0, r = 1;
	long long res = 0;
	unordered_map<int, int> cnt;
	for(int l=1; l<=n; ++l) {
 
		for(;r<=n;++r) {
			if(++cnt[v[r]] == 1) d ++;
 
			if(d > t) {
				if(--cnt[v[r]] == 0) d--;
				break ;
			}
			res += r - l + 1;
		}
		// cout << l << ' ' << r<<endl;
		// for(auto x : s) cout << x << ' ' ;cout << endl;
		// cout << l << ' ' << r << endl;
		if(--cnt[v[l]] == 0) d--;
	}
	cout << res; 
	return 0;
}
