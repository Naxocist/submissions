#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


int c[5];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for(int i=0; i<n; ++i){
        int x; cin >> x;
        c[x]++;
    }

    for(int i=0; i<5; ++i){
        for(int j=0; j<c[i]; ++j) cout << i << ' ';
    }

    return 0;
}
