#include <bits/stdc++.h>
using namespace std;

int expo(int n, int p) {
    int res = 1;

    while(p) {
        if(p&1) res *= n;
        n *= n;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n, p; scanf("%d%d", &n, &p);

    cout << expo(n, p);
}