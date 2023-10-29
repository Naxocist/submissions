#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
using tiii = tuple<int, int, int>;


int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n; scanf("%d", &n);
    vector<tiii> v(n);
    int a, b, c;
    for(int i=0; i<n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        v[i] = tie(a, b, c);
    }

    sort(v.begin(), v.end()) ;
    int k = 0;
    for(int i=0; i<n; ++i) {
        tie(a, b, c) = v[i];
        for(int j=i-1; j>=0; --j) {
            int x, y, r; tie(x, y, r) = v[j];
            if(a - x >= 20) break ; 

            if((a-x)*(a-x) + (b-y)*(b-y) < (c + r) * (c + r)) k++;
            
        }
    }

    cout << k;
    return 0;
}