#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
int main() {
 
    int n; scanf("%d", &n);
    double ar[n];
    for(int i=0; i<n; ++i) scanf("%lf", &ar[i]);
 
    sort(ar, ar+n);
    double k;
    if(n&1) k = ar[n/2];
    else k = (ar[n/2 - 1] + ar[n/2]) /2;
 
    double res = 0;
    for(int i=0; i<n; ++i) {
        res += abs(ar[i] - k);
    }
 
    printf("%lld", (long long int)res);
    return 0;
}
