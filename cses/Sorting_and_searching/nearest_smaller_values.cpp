#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int main() {
	int n; cin >> n;
	vector<int> v(n+1), res(n+1); for(int i=1; i<=n; ++i) cin >> v[i];
 
	stack<pi> st; st.emplace(v[1], 1);
	for(int i=1; i<=n; ++i) {
		while(st.size() and st.top().first >= v[i]) st.pop();
 
		if(st.size()) res[i] = st.top().second;
		st.emplace(v[i], i);
	}
 
	for(int i=1; i<=n; ++i) cout << res[i] << ' ';
	return 0;
}
