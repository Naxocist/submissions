#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
using pi = pair<int, int>;
using pii = pair<int, pi>;
 
const int N = 2e5 + 3;
int desire[N], ap[N];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
	int n, m, d; cin >> n >> m >> d;
 
	for(int i=0; i<n; ++i) cin >> desire[i];
	for(int j=0; j<m; ++j) cin >> ap[j];
 
 
	sort(desire, desire+n);
	sort(ap, ap+m);
	
	int cnt=0, a=0, b=0;
	while(a < n && b < m){
		if(abs(desire[a] - ap[b]) <= d) cnt++, a++, b++;
		else{
			if(desire[a] - ap[b] > d) b++;
			else a++;
		}
	}
 
	cout << cnt;
	return 0;
}
