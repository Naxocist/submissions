#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    string s; cin >> s;
 
    int mx = -1e9, cnt=0;
    char c = s[0];
    for(auto x : s){
        if(x != c){
            mx = max(mx, cnt);
            cnt = 0;
            c = x;
        }
        cnt++;
    }
 
    mx = max(mx, cnt);
 
    printf("%d", mx);
    return 0;
}
