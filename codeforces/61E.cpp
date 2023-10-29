#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;
const int N = 1e6 + 7;
ll fw1[N], fw2[N];

void upd(int i, ll x, ll fw[]) {
	for(;i<N;i+=i&-i) fw[i] += x; 
		return ;
}

int qry(int i, ll fw[]) {
	ll s = 0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n+1), pos;
	for(int i=1; i<=n; ++i) cin >> v[i], pos.push_back(v[i]);

	sort(pos.begin(), pos.end());
	pos.erase(unique(all(pos)), pos.end());

	ll res = 0;
	for(int i=n; i>=1; --i) {
		int t = lower_bound(all(pos), v[i]) - pos.begin() + 1;
		res += qry(t-1, fw2) ;
		upd(t, qry(t-1, fw1), fw2);
		upd(t, 1, fw1);
	}

	cout << res;
	return 0;
}