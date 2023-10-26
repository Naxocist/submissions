#include <bits/stdc++.h>
using namespace std;

// kadane's algorithm
int main(){
    int n; scanf("%d", &n);
    long long mx=0, s;

    scanf("%ld", &s);
    while(--n){
        long long x; scanf("%ld", &x);
        s = max(x, s+x);
        mx = max(s, mx);
    }

    mx = max(s, mx);
    printf("%ld", mx);
    return 0;
}
