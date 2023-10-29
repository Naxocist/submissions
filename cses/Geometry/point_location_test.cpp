#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
int main() {
 
    int n; scanf("%d", &n);
 
    while(n--) {
        ll x, y, a, b, h, k; scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &a, &b, &h, &k);
 
        // (x,y)->(a,b) check (h,k)
 
        // (a,b)->(h,k)
        a -= x; b -= y; h -= x; k -= y;
        ll res = a*k - h*b;
        // printf("%lld", res);
        if(res > 0) printf("LEFT");
        else if(res < 0) printf("RIGHT");
        else printf("TOUCH");
 
        printf("\n"); 
    }
    return 0;
}