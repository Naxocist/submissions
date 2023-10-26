#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

bool cmp(pi a, pi b) {
	if(a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;

    vector<pi> v(n);
    for(auto &x : v) cin >> x.first >> x.second;
    sort(all(v), cmp);
	
	vector<int> dp(100);
	for(int i=0; i<1<<n; ++i) {
		bool ok = 1;
		int t = -1;
		for(int j=0; j<n; ++j) {
			if(i&(1<<j)) {
				int x = v[j].second;
				if(t == -1) t = x;
				else if(t >= x) ok = 0;
				else t = x;
			}
		}
		// cout << countBit(i) << endl;
		if(ok) dp[countBit(i)]++;
	}

    while(m--) {
    	int t; cin >> t;
    	cout << dp[t] << '\n';
    }
    return 0;
}
