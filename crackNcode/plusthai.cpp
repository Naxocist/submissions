#include <bits/stdc++.h>
using namespace std;

int main() {

	string a, b; cin >> a >> b;
	long long n = 0, m = 0;
	for(int i=2; i<a.size(); i+=3) n*=10, n += a[i]-'\x90';
	for(int i=2; i<b.size(); i+=3) m*=10, m += b[i]-'\x90';
	n += m;
	string s;
	for(;n;n/=10) {
		char c = (n%10) + '\x90';
		s = c + s;
		s = "\xe0\xb9" + s;
	}
	cout << s;
	return 0;
}