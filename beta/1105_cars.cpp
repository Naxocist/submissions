#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 3;
bool ar[N];

int main() {

    int n, k; scanf("%d%d", &n, &k);
    while(n--) {
        int x; scanf("%d", &x);
        ar[x] = 1;
    }

    int c = 0;
    for(int i=2e6; i>=1; --i) {
        if(ar[i]) c++;

        if(c == k) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}