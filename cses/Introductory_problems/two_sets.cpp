#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
 
int main() {
	
	ll n; scanf("%lld", &n);
 
	long long s = (n*(n+1))/2;
 
	if(s&1){
		printf("NO");
		return 0;
	}
	s /= 2;
 
	long long s1 = 0;
	ll c = 0, q = 0;
 
	vector<ll> v, y;
	for(ll i=n; i>=1; --i){
		if(s1 + i <= s){
			s1 += i; c++;
			v.push_back(i);
		}else{
			q++;
			y.push_back(i);
		}
	}
 
	printf("YES\n");
	printf("%lld\n", c);
	for(auto x : v) printf("%lld ", x);
 
	printf("\n%lld\n", q);
	for(auto x : y) printf("%lld ", x);
	
	printf("\n");
	
	return 0;
}
