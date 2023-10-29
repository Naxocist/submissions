#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void f() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	int s = 0, mna = 1e9, mxb = 0, mxa = 0;
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;

	for(int i=1; i<=200 and k; i++, k--) {
		sort(a.begin(), a.end()); sort(b.begin(), b.end());
		
	}

	if(k&1) s = max(s - mna + mxb, s);
	cout << s << '\n';
}

int main() {
	int n; cin >> n;
	while(n--) f();
	return 0;
}