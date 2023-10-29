#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
using T = tuple<int, int, int>;
int x, n, q, a, b, fw[N];
char k;
vector<int> v, ar;
 
int sum(int x) {
	int s = 0, i = upper_bound(v.begin(), v.end(), x) - v.begin();
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}	
 
void upd(int x, int y) {
	int i = upper_bound(v.begin(), v.end(), x) - v.begin();
	for(;i<=v.size();i+=i&-i) fw[i] += y;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	set<int> s;
	for(int i=1; i<=n; ++i) {
		cin >> x; s.insert(x); ar.emplace_back(x);
	}
 
	vector<T> Q;
	while(q--) {
		cin >> k >> a >> b;
		Q.emplace_back(k == '?', a, b);
		if(k == '!') s.insert(b);
	}
	
	for(auto x : s) v.emplace_back(x);
 
	for(auto x : ar) upd(x, 1);
	for(auto e : Q) {
		int k; tie(k, a, b) = e; a--;
		if(k) cout << sum(b) - sum(a) << '\n';
		else {
			upd(ar[a], -1);
			upd(b, 1);
			ar[a] = b;
		}
	}
	return 0;
}
