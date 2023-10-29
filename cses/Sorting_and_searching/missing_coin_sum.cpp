#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int N = 2e5 + 3;
int ar[N];
 
int main() {
 
	int n; scanf("%d", &n);
 
	for(int i=0; i<n; ++i) scanf("%d", &ar[i]);
	sort(ar, ar+n);
	ll res = 1;
	for(int i=0; i<n && ar[i] <= res; ++i) {
		res += (ll)ar[i];
	}
	printf("%lld", res);
	return 0;
}
