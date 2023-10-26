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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
	int n, c, d; cin >> n >> c >> d;

	vector<int> v(n);
	for(auto &x : v) cin >> x;

	vector<bool> dp(n+1);
	dp[1] = 1;
	for(int i=1; i<=n; ++i) {
		if(i+c-1 <= n) dp[i+c-1] = dp[i+c-1] or dp[i];
		if(i+d-1 <= n) dp[i+d-1] = dp[i+d-1] or dp[i];
	}

	int r = 0;
	for(auto x : v) r += x%2;
	cout << (dp[n] and r&1 ? "Yes" : "No");
    return 0;
}
