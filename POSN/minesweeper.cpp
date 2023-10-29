#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

const int N = 1e2 + 5;
int a[N][N], chk[N][N];

int main()
{
    int n, m, b; scanf("%d %d %d", &n, &m, &b);

    for(int i=1; i<=b; ++i){
        int x, y, r; scanf("%d %d %d", &y, &x, &r);
        for(int j=y; j<y+r; ++j){
            for(int k=x; k<x+r; ++k) chk[j][k] = i;
        }
    }

    unordered_set<int> s;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(chk[i][j] != 0) {
                printf("*");
                continue;
            }
            for(int q=max(1, i-1); q<=min(n, i+1); ++q){
                for(int w=max(1, j-1); w<=min(m, j+1); ++w){
                    if(chk[q][w] != 0) s.insert(chk[q][w]);
                }
            }
            printf("%d", s.size());
            s.clear();
        }
        printf("\n");
    }
    return 0;
}
