#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
multiset<int> s1, s2;
int ar[N], n, k;
 
void edit() {
	while(s1.size() < (k+1)/2 and s2.size()) {
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	while(s2.size() < k/2 and s1.size()) {
		s2.insert(*(--s1.end()));
		s1.erase(--s1.end());
	}
}
 
void dl(int d) {
	if(d <= *(--s1.end())) s1.erase(s1.find(d));
	else s2.erase(s2.find(d));
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<k-1; ++i) {
		cin >> ar[i];
		s2.insert(ar[i]);
	}
 
	for(int i=k-1; i<n; ++i) {
		int &x = ar[i];
		cin >> x;
		if(s1.size() and x <= *(--s1.end())) s1.insert(x);
		else s2.insert(x);
		if(i>=k) dl(ar[i-k]);
		edit();
		cout << *(--s1.end()) << ' ';
	}
	return 0;
}
