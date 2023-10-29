#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;
	int one = 0, zero = 0;
	for(char c : s) {
		if(c == '1') one ++ ;
		else zero ++;
	}

	cout << n - 2*min(one, zero);
	return 0;
}