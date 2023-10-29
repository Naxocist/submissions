#include <bits/stdc++.h>
using namespace std;
const int N = 43;
using ll = long long;
ll n, s, m, ar[N];
 
vector<ll> f(int l, int r) {
	int len = r-l+1, cnt = 0;
	vector<ll> t;
	for(int i=0; i<1<<len; ++i) {
		ll sum = 0;
 
		for(int j=0; j<len; ++j) {
			if(i&(1<<j)) {
				sum += ar[j	+ l];
			}
		}
		t.emplace_back(sum);
	}
 
	return t;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> s;
	for(int i=0; i<n; ++i) cin >> ar[i];
 
	m = n/2;
 
	vector<ll> a = f(0, m-1); 
	vector<ll> b = f(m, n-1); 
	sort(b.begin(), b.end());
	ll res = 0;
	for(auto e : a) {
		res += upper_bound(b.begin(), b.end(), s-e) - lower_bound(b.begin(), b.end(), s-e);
	}
 
	cout << res;
	return 0;
}