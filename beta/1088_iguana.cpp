#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e8+3;

int main() {

    int n, m; scanf("%d%d", &n, &m);
    vector<pi> v;
    while(m--) {
        int x, y; scanf("%d%d", &x, &y);
        v.emplace_back(x, 1); v.emplace_back(y+1, -1);
    }
    v.emplace_back(1, 0); v.emplace_back(n+1, 0);
    sort(v.begin(), v.end());

    char c; scanf(" %c", &c);
    int t;
    if(c == 'R') t = 3;
    else if(c == 'G') t = 4;
    else t = 5;

    int res = 0, k = 0;
    for(int i=0; i<v.size()-1; ++i) {
        k += v[i].second;
        res += ((t - (k%3))%3) * (v[i+1].first - v[i].first);
    }

    printf("%d", res);
    return 0;
}