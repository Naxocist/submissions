#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n, k; scanf("%d%d", &n, &k);
    pair<int, int> ar[n];
    for(int i=0; i<n; ++i) scanf("%d", &ar[i].first), ar[i].second = i+1;
    sort(ar, ar+n);
 
    int l = 0, r = n-1;
    while(l < r) {
        int m = ar[l].first + ar[r].first;
        if(m == k) {
            printf("%d %d", ar[l].second, ar[r].second);
            return 0;
        }
        if(m < k) {
            l++;
        }else {
            r--;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}
