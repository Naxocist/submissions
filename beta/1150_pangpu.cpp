#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 3;
bool ok[N], t[N];

int main() {

    int n; scanf("%d", &n);

    ok[30000] = 1;
    while(n--) {
        int x; scanf("%d", &x);

        for(int i=0; i<=6e4; ++i) {
            t[i] = ok[i];
        }

        for(int i=0; i<=6e4; ++i) {
            if(!ok[i]) continue ;
            int y = i + x;
            if(y < 0) y += 60001;
            if(y > 6e4) y -= 60001;
            t[y] = 1;
        }
        
        for(int i=0; i<=6e4; ++i) {
            ok[i] = t[i];
        }
    }


    for(int i=6e4; i>=3e4; --i) {
        if(ok[i]) {
            printf("%d", i-30000);
            return 0;
        }
    }
    return 0;
}

/*
5
10 21 -31 17 -29999

*/