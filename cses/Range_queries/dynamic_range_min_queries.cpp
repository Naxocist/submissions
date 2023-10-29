#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3;
int ar[N], segt[3*N], l, r;
 
void build(int i, int L, int R) { 
    if(L == R) {
        segt[i] = ar[L];
    }
    else{
        int M = L + (R - L)/2;
 
        build(2*i+1, L, M); build(2*i+2, M+1, R);
 
        segt[i] = min(segt[2*i+1], segt[2*i+2]);
    }
 
    return ;
}
 
void update(int i, int L, int R, int j) {
    if(L == R) segt[i] = ar[j];
    else {
        int a = 2*i+1, b = 2*i+2, M = L + (R-L)/2;
 
        if(j <= M) update(a, L, M, j);
        else update(b, M+1, R, j);
 
        segt[i] = min(segt[a], segt[b]);
    }
 
    return ;
}
 
 
int query(int i, int L, int R) {
    if(r < L || l > R) return 2e9;
 
    if(l <= L && r >= R) return segt[i];
 
    int M = L + (R-L)/2;
    int a = query(2*i+1, L, M), b = query(2*i+2, M+1, R);
 
    return min(a, b);
}
 
 
int main() {
 
    int n, q; scanf("%d%d", &n, &q);
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);
 
    build(0, 0, n-1);
 
    while(q--) {
        int c;
        scanf("%d%d%d", &c, &l, &r);
        
        if(c == 1) {
            l--;
            ar[l] = r;
            update(0, 0, n-1, l);
        }else {
            l--;r--;
            printf("%d\n", query(0, 0, n-1));
        }
    }
    return 0;
}
