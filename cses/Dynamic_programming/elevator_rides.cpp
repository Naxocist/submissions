#include <bits/stdc++.h>
using namespace std;
 
const int N = 21;
using pi = pair<int, int>;
vector<pi> res(1<<N);
 
int main() {
 
    int n, k; scanf("%d %d", &n, &k);
 
    vector<int> w(n);
    for(int i=0; i<n; ++i) scanf("%d", &w[i]);
 
    for(int i=1; i<1<<n; ++i) {
        res[i] = {n, 0};
        for(int j=0; j<n; ++j) {
            if(i & (1 << j)) {
                pi prev = res[i ^ (1 << j)];
 
                if(prev.second + w[j] <= k) {
                    prev.second += w[j];
                }else {
                    prev.first ++;
                    prev.second = w[j];
                }
 
                res[i] = min(res[i], prev);
            }
        }
 
    }
 
    printf("%d", res[(1<<n) - 1].first + 1);
    return 0;
}
