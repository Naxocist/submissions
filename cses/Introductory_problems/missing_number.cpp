#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n=0, s=0, x=0; scanf("%ld", &n);
 
    for(int i=0; i<n-1; ++i){
        scanf("%ld", &x);
        s += x;
    }
 
    x = ((n+1)*n)/2;
    printf("%ld", x-s);
 
    return 0;
}
