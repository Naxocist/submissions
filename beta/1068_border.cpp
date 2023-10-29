#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

using ll = long long;

const int N = 103;

int ar[2*N][N];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    
    int n, k; scanf("%d%d", &n, &k);
    int r = 2*n+1, c = n;

    for(int i=0; i<r; ++i) {
        for(int j=0; j<c+i%2; ++j) {
            scanf("%d", &ar[i][j]);
        }
    }


    vector<int> v;
    for(int i=0; i<r-1; i+=2) {
        for(int j=0; j<c; ++j) {
            v.push_back(3*(ar[i][j] - ar[i+2][j]) + 5*(ar[i+1][j] - ar[i+1][j+1])); // ตัดกันเองแบบ magic 555
        }
    }

    sort(v.begin(), v.end());
    ll res = 0;
    for(int i=0; i<k; ++i) res += v[i];

    cout << res;
    return 0;
}