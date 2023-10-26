#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;
const int N = 1e6 + 3;
vector<int> lis;

int main() {
    // freopen("input.in", "r", stdin);
    int n; scanf("%d", &n);
    int mx = -1e9;
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);

        auto it = upper_bound(lis.begin(), lis.end(), x);

        if(it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    printf("%d", n - lis.size());
    
    return 0;
}
