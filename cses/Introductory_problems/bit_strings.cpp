#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n; scanf("%d", &n);
    long long k = 1;
    while(n--){
        k = (k*2)%(1000000000 + 7);
    }
 
    printf("%ld", k);
    return 0;
}
