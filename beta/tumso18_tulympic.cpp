#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
vector<pi> ar[7];

int main() {

    int n, m, x, t; scanf("%d%d%d%d", &n, &m, &x, &t);

    vector<int> s(n);
    for(int i=0; i<n; ++i) scanf("%d", &s[i]);


    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            int y; scanf("%d", &y);
            ar[j].emplace_back(y, i);
        }
    }

    vector<int> r(n, 0);

    for(int i=0; i<m; ++i) {
        sort(ar[i].begin(), ar[i].end());

        for(int j=0; j<n; ++j) {
            r[ar[i][j].second] += s[j];
        }
    }

    vector<pi> res;
    for(int i=0; i<n; ++i)res.emplace_back(r[i], i);
    sort(res.rbegin(), res.rend());

    x--;
    for(int i=0; i<n; ++i) {
        if(res[i].second == x) {
            printf("%d", i+1);
            if(t == 2) printf(" %d", res[i].first);

            return 0;
        }
    }
    return 0;
}