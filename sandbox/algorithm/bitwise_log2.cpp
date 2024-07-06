#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n; scanf("%d", &n);
    cout << 31 - __builtin_clz(n) << '\n'; // log2
    return 0;
}