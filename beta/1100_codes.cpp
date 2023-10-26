#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

using ll = long long;
using pi = pair<int, int>;
using pii = pair<pi, int>;

int a[3][10], b[3][100], c[1000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    ll cnt = 0;
    
    while(n--){
        int s; cin >> s;

        int d = s%10, t = (s/10)%10, h = s/100; // 001 010 100
        int x = s/10, y = s%100, z = (s/100)*10 + s%10;// 110 011 101

        cnt += a[0][d] + a[1][t] + a[2][h]; 
        cnt -= b[0][x] + b[1][y] + b[2][z]; 
        cnt += c[s]; // 111

        a[0][d]++; a[1][t]++; a[2][h]++; 
        b[0][x]++; b[1][y]++; b[2][z]++;
        c[s]++; // 111
    }
    cout << cnt;
    return 0;

}

