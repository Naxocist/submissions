#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 2553;

ll p[65][5][5], t[5];

void mul(int z) {
    for(int i=1; i<=4; ++i) {
        for(int j=1; j<=4; ++j) {
            for(int k=1; k<=4; ++k) {
                p[z][i][j] += p[z-1][i][k]*p[z-1][k][j], p[z][i][j] %= mod;
            }
        }
    }
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll a, b, k, y; cin >> a >> b >> k >> y;

	for(int i=1; i<4; ++i) p[0][i][i+1] = 1;
	for(int j=4; j>=1; --j) cin >> p[0][4][j];
    for(int i=1; i<=64; ++i) mul(i);

	int q; cin >> q;
	while(q--) {
		ll n; cin >> n;
		ll c = 0, d[5] = {0LL, a, b, k, y};
		if(n <= 4) {
			cout << d[n] << '\n'; continue ;
		}
		n -= 4;
    	while(n) {
    		if(n&1){
    		    t[1] = ((p[c][1][1]*d[1])%mod + (p[c][1][2]*d[2])%mod + (p[c][1][3]*d[3])%mod + (p[c][1][4]*d[4])%mod)%mod;
    		    t[2] = ((p[c][2][1]*d[1])%mod + (p[c][2][2]*d[2])%mod + (p[c][2][3]*d[3])%mod + (p[c][2][4]*d[4])%mod)%mod;
    		    t[3] = ((p[c][3][1]*d[1])%mod + (p[c][3][2]*d[2])%mod + (p[c][3][3]*d[3])%mod + (p[c][3][4]*d[4])%mod)%mod;
    		    t[4] = ((p[c][4][1]*d[1])%mod + (p[c][4][2]*d[2])%mod + (p[c][4][3]*d[3])%mod + (p[c][4][4]*d[4])%mod)%mod;
    		    for(int i=1; i<=4; ++i) d[i] = t[i];
    		}
    		c++;
    		n>>=1;
    	}
    	cout << d[4] << '\n';
	}

	return 0;

}