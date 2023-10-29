#include <bits/stdc++.h>
using namespace std;

const int N = 103;
bool v[N][N];

int main() {

    int n, k; scanf("%d%d", &n, &k);

    for(int i=0; i<k; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        v[x][y] = 1;
    }
    int res = 1e9;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(v[i][j]) {
                for(int i=1; i<=k/2; ++i) {
                    if(k % i) continue ; 
                    int x = k/i, y = i; // x * y = k;
                    if(i + x - 1 <= n && j + y - 1 <= n) {
                        int cnt = 0;
                        for(int h=i; h<=i+x-1; ++h) 
                            for(int g=j; g<=j+y-1; ++g) cnt += v[h][g];

                        res = min(res, k - cnt);
                    }
                    swap(x, y);
                    if(i + x - 1 <= n && j + y - 1 <= n) {
                        int cnt = 0;
                        for(int h=i; h<=i+x-1; ++h) 
                            for(int g=j; g<=j+y-1; ++g) cnt += v[h][g];

                        res = min(res, k - cnt);
                    }
                    

                }

                printf("%d", res);
                return 0;
            }
        }
    }
    return 0;
}