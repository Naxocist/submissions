#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);

    int m = n/2;
    bool c = n%2;

    for(int i=0; i<m; ++i) {

        bool s = 1;
        int k = i;
        for(int j=0; j<m; ++j) {
            
            if(s) printf("*");
            else printf("-");

            if(j < i) s = not s;
        }
        if(c) cout << (s ? "*" : "-");
        for(int j=m-1; j>=0; --j) {
            
            if(s) printf("*");
            else printf("-");

            if(j <= i) s = not s;
        }
        cout << '\n';
    }
    
    if(c) {
        for(int i=0; i<n; ++i) {
            cout << (i%2 ? "-" : "*");
        }
        cout << '\n';
    }
    for(int i=m-1; i>=0; --i) {

        bool s = 1;
        int k = i;
        for(int j=0; j<m; ++j) {
            
            if(s) printf("*");
            else printf("-");

            if(j < i) s = not s;
        }
        if(c) cout << (s ? "*" : "-");
        for(int j=m-1; j>=0; --j) {
            
            if(s) printf("*");
            else printf("-");

            if(j <= i) s = not s;
        }
        cout << '\n';
    }
    return 0;
}