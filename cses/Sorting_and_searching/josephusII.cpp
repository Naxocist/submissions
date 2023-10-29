#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int fw[N], n, k;
 
int qry(int i) {
	int s = 0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}
 
void upd(int i, int x) {
	for(;i<=n;i+=i&-i) fw[i] += x;
}
 
int bs(int x) {
	int l = 1, r = n, res = 0;
	while(l <= r) {
		int md = l + (r-l)/2;
		if(qry(md) >= x) r = md - 1, res = md;
		else l = md + 1;
	}
	return res;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		fw[i] += 1;
		int j = i + (i&-i);
		if(j <= n) fw[j] += fw[i];
	}
	
	int now = 1;
	for(int sz=n; sz>0; sz--) {
		now = ( (now + k - 1) % sz ) + 1;
		int out = bs(now);
		cout << out << ' ';
		upd(out, -1);		
	}
 
	return 0;
}
