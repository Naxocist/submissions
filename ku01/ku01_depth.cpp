#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int N = 1e5 + 3;
int v[N];
int sum = 0, lvl = 0, mx = 0;
stack<pi> st;

void f() {
	int a, b, c, d; 
	tie(a, b) = st.top(); st.pop();
	tie(c, d) = st.top();
	v[a] = max(v[a], b-d);
	st.top().second = sum;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	
	st.emplace(0, 0);
	while(n--) {
		int d, l; cin >> d >> l;
		lvl += d, sum += l;
		if(d == 1) st.emplace(lvl, sum);
		else f();
		mx = max(mx, lvl);
	}
	while(st.size() > 1) f();
	reverse(v, v+mx+1);
	while(q--) {
		int x; cin >> x;
		int t = lower_bound(v, v+mx, x) - v;
		cout << mx - t << '\n';
	}
	return 0;
}