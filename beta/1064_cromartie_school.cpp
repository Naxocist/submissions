#include <bits/stdc++.h>
using namespace std;

const int N = 70;
char ar[N][N]; 
bool fll[N][N];
int n, m, a, b;

void fld(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || ar[i][j] != 'P' || fll[i][j]) return ;
    fll[i][j] = 1;
    // printf("%d %d\n", i, j);
    fld(i+1, j);
    fld(i, j+1);
    fld(i-1, j);
    fld(i, j-1);
    return ;
}


void f(int i, int j, int k) {
    int c = 0;
    for(int h=i; h<=i+k-1; ++h) {
        for(int g=j; g<=j+k-1; ++g) {
            // printf("%d %d\n", h, g);
            if(ar[h][g] == 'T') return ;
            if(ar[h][g] == 'P' && !fll[h][g]) fld(h, g), c++;
        }
    }
    if(k * k > a || (k * k == a && c < b)) {
        a = k*k;
        b = c;
    }
    return ;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;

    for(int i=0; i<n; ++i) {
        string s; cin >> s;
        for(int j=0; j<m; ++j) {
            ar[i][j] = s[j];
        }
    }

    for(int k = min(n, m); k>=1; --k) {
        for(int i=0; i+k-1<n; ++i) {
            for(int j=0; j+k-1<m; ++j) {
                f(i, j, k);
                memset(fll, false, sizeof fll);
            }
        }
    }

    printf("%d %d", a, b);
    return 0;
}