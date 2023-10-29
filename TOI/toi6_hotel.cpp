#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int main() {
	int n; scanf("%d", &n);
	int res = 0;
	while(n > 0) {
		if(n >= 9) res += 3000, n -= 15;
		else if(n >= 4) res += 1500, n -= 5;
		else if(n >= 2) res += 800, n -= 2;
		else res += 500, n--;
	}
	printf("%d", res);
	return 0;
}