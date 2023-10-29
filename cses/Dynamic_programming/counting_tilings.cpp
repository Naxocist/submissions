#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, vector<int>> prv;
ll mod = 1e9 + 7;
ll dp[2][1<<11];
int n, m;
 
void gen(int i, int now, int nxt) {
	if(i > n) return ;
	if(i == n) {
		prv[nxt].emplace_back(now);
		return ;
	}
 
	if((now&(1<<i)) != 0) {
		gen(i+1, now, nxt);
	}else {
		if((now&(1<<(i+1))) == 0) gen(i+2, now, nxt);
		gen(i+1, now, nxt | (1<<i) );
	}
	return ;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
 
	for(int i=0; i<1<<n; ++i) gen(0, i, 0);
 
	dp[0][0] = 1;
 
	for(int j=1; j<=m; ++j) {
		for(int i=0; i<1<<n; ++i) {
			dp[j&1][i] = 0;
			for(int p : prv[i])
				dp[j&1][i] += dp[j&1^1][p], dp[j&1][i] %= mod;
		}
	}
 
	cout << dp[m&1][0];
	return 0;
}
