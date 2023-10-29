#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
string s;
 
 
int main() {
 
	int n; scanf("%d", &n);
	ll s = 0;
	vector<ll> v;
	for(int i=0; i<n; ++i){
		ll x; scanf("%lld", &x);
		s += x;
		v.push_back(x);
	}
 
	int k = pow(2, n);
	ll mn = 1e9;
	for(int i=0; i<k; ++i){
		int bits = i;
		ll h = 0;
		for(int j=0; j<n; ++j, bits>>=1){
			if(bits&1){
				h += v[j];
			}
		}
		mn = min(mn, abs(h - (s - h)));
	}
 
	printf("%lld", mn);
	return 0;
}
