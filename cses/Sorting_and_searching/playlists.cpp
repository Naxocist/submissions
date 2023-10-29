#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int ar[N];
int main() {
	int n; scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);
 
	map<int, bool> s;
	int sz = 1, mx = 1;
	int l = 1, r = 1;
	while(r <= n) {
		int x = ar[r];
		if(s[x] == false) {
			s[x] = true;
			mx = max(mx, sz);
			sz ++;
			r++;
		}else {
			s[ar[l]] = false;
			sz--;
			l ++;
		}
	}
	printf("%d", mx);
	return 0;
}
