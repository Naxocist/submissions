#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void f() {
	int a, b, t; cin >> a >> b >> t;
	ll res = b-1;
	while(t--) {
		int x; cin >> x;
		if(1+x <= a) res += x;
		else res += a-1;
	}
	res ++;
	cout << res << '\n';
}

int main() {
	int n; cin >> n;
	while(n--) f();
	return 0;
}