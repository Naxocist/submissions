#include <bits/stdc++.h>
using namespace std;
 
int M = 1e9 + 7;
 
int main() {
    
    int n; scanf("%d", &n);
 
    int c = 0;
    while(n) {
        int k = n, mx = 0;
 
        while(k) {
            mx = max(mx, k%10);
            k/=10;
        }
        n-=mx;
        c++;
    }
 
    printf("%d", c);
    return 0;
}
