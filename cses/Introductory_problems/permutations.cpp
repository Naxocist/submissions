#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n; scanf("%d", &n);
 
    if(n == 1) {
        printf("1");
        return 0;
    }
    if(n <= 3) {
        printf("NO SOLUTION");
        return 0;
    }
 
    int c = n-2, x = -1, t = n;
    n--;
    while(c){
        printf("%d ", n);
        n += (x*c);
        x *= -1;
        c--;
    }
    printf("%d %d", t, n);
    return 0;
}
