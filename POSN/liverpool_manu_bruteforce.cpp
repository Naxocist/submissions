#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1e5;
int ar[N];

int main() {

	int n; cin >> n;

	int k = 1;
	while(n--) {
		int t; cin >> t; 
		string s; cin >> s;
		while(t--)
		for(char c : s) {
			int x = c - '0';
			ar[k++] = x;
		}
	}	
	n = k-1;

	int q; cin >> q;
	while(q--) {
		char c; int l, r; cin >> c >> l >> r, l++ , r++;

		if(c == 'F') {
			for(;l<=r;++l) ar[l] = 1;
		}else if(c == 'E') {
			for(;l<=r;++l) ar[l] = 0;
		}else if(c == 'I') {
			for(;l<=r;++l) ar[l] = !ar[l];
		}else {
			int s = 0;
			for(;l<=r;++l) s += ar[l];
			cout << s << '\n';
		}
	}
	return 0;
}