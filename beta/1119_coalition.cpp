#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

int main() {

    int n; scanf("%d", &n);
    vector<pi> v;
    vector<int> res(n), q(n);
    int s = 0;
    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x); 
        v.emplace_back(x, i);
        s += x;
    }
    s = s / 2  + 1;
    sort(v.rbegin(), v.rend());
    q[0] = v[0].first;

    int w = (q[0] >= s ? 1 : -1);
    for(int i=1; i<n; ++i) {
        q[i] = q[i-1] + v[i].first;
        if(q[i] >= s && w < 0) w = i;
    }

    // cout << w << endl;
    for(int j=0; j<v.size(); ++j) {
        int k = v[j].first, i = v[j].second;

        if(j <= w) {
            res[i] = w;
            continue ;
        }
        int t = lower_bound(q.begin(), q.end(), s - k) - q.begin();
        res[i] = t + 1;
    }

    for(int x : res) printf("%d\n", x);
    return 0;
}
/*
5 5 6 7 5 5 8

8 7 6 | 5 5 5 5
*/