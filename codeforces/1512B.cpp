#include <bits/stdc++.h>
using namespace std;
#define D 0

void f() {
	int n; cin >> n;
	int a, b, c, d; a=b=c=d=0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			char k; cin >> k;
			if(k == '*') {
				if(!a) a = i, b = j;
				else c = i, d = j;
			}
		}
	}
	
	if(a == c) {
		if(c == 1) c++;
		else if(c == n) c--;
		else c++;
	}

	if(b == d) {
		if(b == 1) b++;
		else if( b == n) b--;
		else b++;
	}
	if(D) cout << a << ' ' << b << '\n' << c << ' ' << d << '\n';
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i == a && j == b) cout << '*';
			else if(i == c && j == d) cout << '*';
			else if(a != c && b != d && ((i == a && j == d) || (i == c && j == b))) cout << '*';
			else cout << '.';
		}
		cout << '\n';
	}
}
int main() {
	int t; cin >> t;
	while(t--) f();
	return 0;
}