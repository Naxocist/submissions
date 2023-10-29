#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
 
int rotate(ll x, ll y, ll a, ll b, ll i, ll j) {
 
    a-=x;b-=y;i-=x;j-=y;
 
    ll c = (a*j) - (b*i);
 
    if(c > 0) return 1;
    if(c < 0) return 2;
    return 0;
}
 
bool sameline(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x3 <= max(x1, x2) && x3 >= min(x1, x2) && y3 <= max(y1, y2) && y3 >= min(y1, y2));
}
 
int main() {
 
    int n; scanf("%d", &n);
 
    while(n--) {
        ll x, y, a, b, h, k, i, j; 
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x, &y, &a, &b, &h, &k, &i, &j);
 
        // (x,y)->(a,b) intersect (h, k)->(i,j) ?
 
        int o1 = rotate(x, y, a, b, i, j);
        int o2 = rotate(x, y, a, b, h, k);
 
        int o3 = rotate(i, j, h, k, x, y);
        int o4 = rotate(i, j, h, k, a, b);
 
        if(o1 != o2 && o3 != o4 ) {
            printf("YES\n"); continue;
        }
 
        if(o1 == 0 && sameline(x, y, a, b, i, j)) {
            printf("YES\n"); continue ;
        }
 
        if(o2 == 0 && sameline(x, y, a, b, h, k)) {
            printf("YES\n"); continue;
        }
 
        if(o3 == 0 && sameline(i, j, h, k, x, y)) {
            printf("YES\n"); continue ;
        }
 
        if(o4 == 0 && sameline(i, j, h, k, a, b)) {
            printf("YES\n"); continue;
        }
        
        printf("NO\n");
    }
    return 0;
}