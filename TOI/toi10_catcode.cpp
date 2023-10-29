#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
bool has[N];
int hsh[N], idx[N];
int t, x, n, sz;
string s;

void fastscan(int &number)
{
	bool negative = false;
	register int c;

	number = 0;
	c = getchar();
	if (c=='-'){
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;
	if (negative)
		number *= -1;
}

void f(int x) {
	for(int i=4; i>=0; --i) {
		if(x & (1 << i)) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false); cout.tie(nullptr);
	fastscan(n); fastscan(sz);

	for(int i=1; i<=n; ++i) {
		cin >> s;
		x = 0;
		for(int j=0; j<sz; ++j) x |= (s[j]-'0')<<j;
		int p = x % N;
		while(hsh[p]) p++, p%=N;
		hsh[p] = i;
		idx[i] = x;
	}
	int q; fastscan(q);
	while(q--) {
		fastscan(t); cin >> s;
		bool ok = 1;
		x = 0;
		for(int i=0; i<sz; ++i) x |= (s[i]-'0')<<i;
		for(int i=0; i+sz-1<t; ++i) {
			if(i) {
				x>>=1;
				x|=(s[i+sz-1]-'0')<<(sz-1);
			}
			// f(x);
			int p = x % N;
			while(hsh[p]) {
				if(idx[hsh[p]] == x) {
					has[hsh[p]] = 1, ok = 0; 
					break ;
				}
				p++, p%=N;
			}
		}
		if(ok) cout << "OK";
		else for(int i=1; i<=n; ++i) {
			if(has[i]) cout << i << ' ';
			has[i] = 0;
		}
		cout << '\n';
	}
	return 0;
}