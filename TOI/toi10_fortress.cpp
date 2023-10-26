#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;


int main() {
    // freopen("input.in", "r", stdin);

    for(int i=0; i<20; ++i){
        ll m, n; 
        scanf("%lld%lld", &m, &n);

        m /= 2;
        ll c = m - n;
        if(c < 0 || c > n){
            printf("0\n");
            continue;
        }
        
        printf("%lld\n", m - (2*c) + 1);

    }
    
    return 0;
}
