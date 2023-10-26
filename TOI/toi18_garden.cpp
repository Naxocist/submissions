#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int ar[N], dp[2][N];
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n, q; scanf("%d%d", &n, &q);
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);


    for(int i=0; i<n; ++i) {
        auto idx = lower_bound(a.begin(), a.end(), ar[i]);
        if(idx == a.end()) a.push_back(ar[i]), dp[0][i] = a.size();
        else {
            *idx = ar[i];
            dp[0][i] = idx - a.begin() + 1;
        }
    }

    a.clear();
    for(int i=n-1; i>=0; --i) {
        auto idx = lower_bound(a.begin(), a.end(), ar[i]);
        if(idx == a.end()) a.push_back(ar[i]), dp[1][i] = a.size();
        else {
            *idx = ar[i];
            dp[1][i] = idx - a.begin() + 1;
        }
    }

    while(q--) {
        int x; scanf("%d", &x);

        cout << min(dp[0][x], dp[1][x]) - 1 << '\n';
    }

    return 0;
}

/*
10 4
2 4 6 8 10 9 7 5 3 1
9 4 0 3
*/