#include <bits/stdc++.h>
using namespace std;

void f() {
	int n; cin >> n;
	int a = 0, b = 0;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		if(i&1 && x&1^1) a++;
		if(i&1^1 && x&1) b++;
	}
	if(a != b) {
		cout << -1 << '\n';
		return ;
	}

	cout << a << '\n';
}
int main() {
	cin.tie(NULL)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--) f();
	return 0;
}