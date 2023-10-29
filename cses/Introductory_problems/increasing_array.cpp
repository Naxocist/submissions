#include <bits/stdc++.h>
using namespace std;
 
long long n, p, curr, mv;
 
int main(){
    scanf("%ld", &n);
    scanf("%ld", &p);
 
    long long mv = 0;
    for(int i=0; i<n-1; ++i){
        scanf("%ld", &curr);
        if(curr >= p) {
            p = curr; 
            continue;
        }
 
        mv += p - curr;
    }
    
    cout << mv;
    return 0;
}
