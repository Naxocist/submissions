#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);

    while(n--) {
        int h, m; scanf("%d%d", &h, &m);

        double l = (20 - h) * 60 + (60 - m) - 15;

        int k = ceil(l/2);

        if(k > 0) {
            printf("%d %d\n", int(l), k);
        }else {
            printf("0 0\n");
        }

    }
    return 0;
}