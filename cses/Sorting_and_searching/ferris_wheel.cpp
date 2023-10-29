#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n, k; scanf("%d%d", &n, &k);
 
    int ar[n];
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);
 
    sort(ar, ar+n, greater<int>());
 
    int l = 0, r = n-1, res = 0;
    while(l <= r) {
        if(ar[l] + ar[r] <= k) {
            l++, r--;
            res ++;
        } else {
            l++;
            res ++;
        }
    }
 
    printf("%d", res);
    return 0;
}
/*
10 20
5 9 6 5 8 9 10 6 5 6
*/
