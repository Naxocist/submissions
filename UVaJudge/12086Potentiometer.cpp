#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int fw[N], ar[N], n;
vector<vector<int>> res;
int qry(int i) {
	int s = 0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}
void upd(int i, int x) {
	for(;i<=n;i+=i&-i) fw[i] += x;
}
void solve() {
	memset(fw, 0, sizeof fw);
	for(int i=1; i<=n; ++i) {
		cin >> ar[i];
		upd(i, ar[i]);
	}
	while(true) {
		string s; int l, r; cin >> s;
		if(s == "END") return ;
		cin >> l >> r;
		if(s == "M") res.back().push_back(qry(r) - qry(l-1));
		else upd(l, r - ar[l]), ar[l] = r;
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(;;){
		cin >> n;
		if(n == 0) break ;
		res.emplace_back(vector<int>());
		solve();
	}
	for(int i=0; i<res.size(); ++i) {
		if(i) cout << '\n';
		cout << "Case " << i+1 << ":\n";
		for(auto x : res[i]) cout << x << '\n';
	}
	return 0;
}