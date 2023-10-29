#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n; scanf("%ld", &n);
 
    while(n != 1){
        printf("%ld ", n);
        if(n & 1) n = n*3 + 1;
        else n /= 2;
    }
 
    printf("1");
 
    return 0;
}
