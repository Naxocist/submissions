#include <bits/stdc++.h>
using namespace std;
vector<int> ar[5];

int main() {

    int n; scanf("%d", &n);

    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            int x; scanf("%d", &x);
            if(i&1 && j&1) ar[0].push_back(x);
            else if(i&1 && j&1^1) ar[1].push_back(x);
            else if(i&1^1 && j&1) ar[2].push_back(x);
            else ar[3].push_back(x);
        }
    }

    for(int i=0; i<4; ++i) sort(ar[i].begin(), ar[i].end(), greater<int>());

    int res = 0;
    for(int i=0; i<(n*n)/4; ++i) {
        int s = 1;
        for(int j=0; j<4; ++j) {
            s *= ar[j][i];
        }
        res += s;
    }

    printf("%d", res);
    return 0;
}
/*
6
1 1 2 1 1 1
1 1 1 2 1 1
1 1 1 1 1 1
1 3 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/