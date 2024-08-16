#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int n=0, m=0;
    cin >> a >> b;
    for(int i=0;i<a.size();i++){
        n+=(a[a.size()-i-1]-'0')*(1<<i);
    }
    for(int i=0;i<b.size();i++){
        m+=(b[b.size()-i-1]-'0')*(1<<i);
    }
    int s=n+m;
    int k = 0, zero = 0;
    while(s) {
        if(s%2 == 1) k++;
        else zero ++;
        s/=2;
    }
    int t= k-1;
    while(t--) cout << 1;
    while(zero--) cout << 0;
    cout << 1;
    return 0;
}
