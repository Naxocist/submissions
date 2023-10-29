#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int p[N];

int main() {

    int n, k; scanf("%d%d", &n, &k);

    int res = 0, c = 0;
    
    while(n--) {
        int x; scanf("%d", &x);
        p[x] ++;
        bool ok = 1;
        for(int i=1; i<=k; ++i) {
            if(p[i] == 0) ok = 0;
        }

        if(!ok) continue ;

        for(int i=1; i<=k; ++i) p[i]--;
    }

    for(int i=1; i<=k; ++i) res += p[i];
    printf("%d", res);
    return 0;
}