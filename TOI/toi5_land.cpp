#include <bits/stdc++.h>
using namespace std;

const int N = 5;
double ar[N][N];
bool choose[N][N];
int n, m;
double res = 1e9;

void f(int q, double r) {
    if(q == n*m) {
        res = min(res, r);
        return ;
    }
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(choose[i][j]) continue ;
            choose[i][j] = 1;
            for(int h=i-1; h<=i+1; ++h) 
                for(int k=j-1; k<=j+1; ++k) {
                    if(h == i && k == j) continue ;
                    ar[h][k] += 0.1 * ar[i][j];
                }
            f(q+1, r+ar[i][j]);
            for(int h=i-1; h<=i+1; ++h) 
                for(int k=j-1; k<=j+1; ++k) {
                    if(h == i && k == j) continue ;
                    ar[h][k] -= 0.1 * ar[i][j];
                }
            choose[i][j] = 0;
        }
    }

    return ;
}



int main() {

    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) scanf("%lf", &ar[i][j]);
    }

    f(0, 0);
    printf("%.2lf", res);
    return 0;
}