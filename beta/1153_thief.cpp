#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
using pi = pair<int, int>;
const int N = 1e3 + 5;
int dp[N][N], n;
vector<T> w;



// int f(int i, int t) {
// 	if(i >= n) return 0;
// 	if(dp[i][t]) return dp[i][t];

// 	int mx = 0;
// 	int s, e, v; tie(s, e, v) = w[i];

// 	mx = max(mx, f(i+1, t)); // ignore

// 	if(t == 0) mx = max(mx, f(i+1, e) + v); // first person
// 	else {
// 		// second person
// 		int k = lower_bound(st.begin() + i + 1, st.end(), min(t, e)) - st.begin();
// 		mx = max(mx, f(k, max(t, e)) + v);
// 	}

// 	return dp[i][t] = mx;

// }


int main() {

	scanf("%d", &n);

	
	for(int i=0; i<n; ++i) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		w.emplace_back(a, b, c);
	}
	sort(w.begin(), w.end());

	vector<int> st(n), ed(n), val(n);
	for(int i=0; i<n; ++i) {
		tie(st[i], ed[i], val[i]) = w[i];
	}
	// printf("%d", f(0, 0));

	for(int i=n-1; i>=0; --i) {
		dp[i][0] = max(dp[i+1][0], dp[i+1][ed[i]] + val[i]); // ignore, first person
		for(int t=1000; t>=1; --t) {
			if(t <= st[i]) {
				dp[i][t] = dp[i][0]; continue ;
			}
			
			int k = lower_bound(st.begin() + i + 1, st.end(), min(t, ed[i])) - st.begin();
			dp[i][t] = max(dp[i+1][t], dp[k][max(t, ed[i])] + val[i]); // ignore, second person
		}
	}

	printf("%d", dp[0][0]);
	return 0;
}