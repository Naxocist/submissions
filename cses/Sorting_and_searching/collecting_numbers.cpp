#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3;
bool s[N];
int main() {
	int n, res = 0; cin >> n;
	
	while(n--) {
		int x; cin >> x;
		if(!s[x-1]) res ++;
		s[x] = true;
	}
	cout << res;
	return 0;
}
