#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n; scanf("%d", &n);
    string res;
    int x = 0; bool b = 1;
    for(int i=0; i<n; ++i) {
        if(b) res += 'a';
        else res += 'b';

        x++;
        if(x == 2) x=0, b = !b;
    }

    
    
    cout << res;
}