#include <bits/stdc++.h>
using namespace std;

int ar[10005], s[10005];

int main(){
    int n; scanf("%d", &n);

    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);
    int mx = 0;
    s[0] = 1;
    for(int i=1; i<n; ++i){
        int t = 0;
        for(int j=i-1; j>=0; --j){
            if(ar[j] < ar[i]){
                t = max(t, s[j]);
            }
        }
        s[i] = t+1;
    }

    for(int i=0; i<n; ++i) mx = max(mx, s[i]);
    printf("%d", mx);
    return 0;
}
