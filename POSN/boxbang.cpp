#include <bits/stdc++.h>
using namespace std;


int a[1005];
int main() {

    int n, t; cin >> n >> t;

    for(int i=0; i<n; ++i) cin >> a[i];

    while(t--){
        int c, pos, h; cin >> c;
        if(c != 4) cin >> pos;

        cin >> h;
        if(h < 1) continue;
        pos--;

        if(c == 1) a[pos] += (h > a[pos]);

        else if(c == 2) a[pos] -= (h <= a[pos]);

        else if(c == 3) {

            for(int j=max(0, pos-1); j<=pos+1 && j < n; ++j){

                for(int i=h+1; i>=max(1, h-1); --i){

                    if(a[j] >= i) a[j]--;
                }
            }
        }
        else for(int i=0; i<n; ++i) a[i]-=(h <= a[i]);

        for(int i=0; i<n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}

/*
6 4
5 3 1 3 3 4
1 3 4
2 5 2
3 2 2
4 3
*/
