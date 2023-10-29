#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int p[N];

int main() {

    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &p[i]); p[i] += p[i-1];
    }

    int mn = 1e9, x, y;
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            int a = p[i-1], b = p[j-1] - p[i-1], c = p[n] - p[j-1];
            if(max({a, b, c}) - min({a, b, c}) < mn) {
                mn = max({a, b, c}) - min({a, b, c});
                x = i ; y = j;
            }
        }
    }

    cout << x << ' ' << y;
    return 0;
}