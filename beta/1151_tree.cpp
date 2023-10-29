#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);
    vector<int> lis;
    while(n--) {
        int x ; scanf("%d", &x);
        auto t = lower_bound(lis.begin(), lis.end(), x);
        if(t == lis.end()) lis.push_back(x);
        else *t = x;
    }

    printf("%d", lis.size());
    return 0;
}