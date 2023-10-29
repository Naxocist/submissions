#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
bool dp[N];
int coin[N];
 
int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> coin[i];
 
	dp[0] = true;
	
	for(int i=1; i<=n; ++i) {
		for(int j=1e5; j>=0; --j) {
			if(j + coin[i] > 1e5) continue ;
			if(dp[j]) dp[j + coin[i]] = true;
		}
	}
 
	int cnt = 0;
	for(int i=1; i<=1e5; ++i) if(dp[i]) cnt ++;
	cout << cnt << '\n';
	for(int i=1; i<=1e5; ++i) if(dp[i]) cout << i << ' ';
	return 0;
}
