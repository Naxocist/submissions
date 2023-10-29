#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;

int main() {

    int n; scanf("%d", &n);

    vector<int> path(n, -1), pile, pileidx, v;
    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x); v.emplace_back(x);

        int t = lower_bound(pile.begin(), pile.end(), x) - pile.begin();

        if(t == pile.size()) {
            pile.emplace_back(x);
            pileidx.emplace_back(i);
        }else {
            pile[t] = x;
            pileidx[t] = i;
        }

        path[i] = (t == 0 || pile.empty() ? -1 : pileidx[t-1]);
    }

    printf("%d\n", pile.size());

    vector<int> res; 
    int r = pileidx.back();
    while(r != -1) {
        res.push_back(v[r]);
        r = path[r];
    }

    for(int i=res.size()-1; i>=0; --i) printf("%d ", res[i]);
    return 0;
}
/*
11
2 4 1 2 5 6 3 9 10 1 11
*/
