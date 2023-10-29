#include <bits/stdc++.h>
using namespace std;
 
// kadane's algorithm
int main(){
    int n; scanf("%d", &n);
    long long int mx, s;
 
    scanf("%lld", &s);
    mx = s;
    while(--n){
        long long int x; scanf("%lld", &x);
        s = max(x, s+x);
        mx = max(s, mx);
    }
 
    mx = max(s, mx);
    printf("%lld", mx);
    return 0;
}
