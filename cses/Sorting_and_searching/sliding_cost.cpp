#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
multiset<int> s1, s2;
int ar[N], n, k;
ll lw, hi;
 
void edit() {
	while(s1.size() < (k+1)/2 and s2.size()) {
		s1.insert(*s2.begin()), lw+=*s2.begin();
		hi -= *s2.begin();
		s2.erase(s2.begin());
	}
	while(s2.size() < k/2 and s1.size()) {
		s2.insert(*s1.rbegin()), hi+=*s1.rbegin();
		lw -= *s1.rbegin();
		s1.erase(--s1.end());
	}
}
 
void dl(int d) {
	if(d <= *s1.rbegin()) s1.erase(s1.find(d)), lw-=d;
	else s2.erase(s2.find(d)), hi-=d;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<k-1; ++i) {
		cin >> ar[i];
		s2.insert(ar[i]); hi += ar[i];
	}
 
	ll res = 0;
	for(int i=k-1; i<n; ++i) {
		int &x = ar[i];
		cin >> x;
		if(s1.size() and x <= *s1.rbegin()) s1.insert(x), lw+=x;
		else s2.insert(x), hi+=x;
		if(i>=k) dl(ar[i-k]);
		edit();
		ll m = *s1.rbegin();
		cout << m*((k+1)/2) - lw + hi - m*(k/2) << ' ';
	}
	return 0;
}
