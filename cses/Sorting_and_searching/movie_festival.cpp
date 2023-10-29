#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n; scanf("%d", &n);
    pair<int, int> ar[n];
 
    for(int i=0; i<n; ++i) {
        scanf("%d%d", &ar[i].second, &ar[i].first);
    }
    sort(ar, ar+n);
 
    int res = 1, d = ar[0].first;
    for(int i=1; i<n; ++i) {
        if(ar[i].second < d) continue ;
        d = ar[i].first;
        res++;
    }
    printf("%d", res);
    return 0;
}
