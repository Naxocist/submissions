#include <bits/stdc++.h>
#define endll '\n'
typedef long long ll;
using namespace std;

int track[10005], whysohard[25];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int r, n; cin >> r >> n;

    for(int i=0; i<n; ++i) cin >> whysohard[i];


    track[0] = 1;

    for(int i=1; i<=r; ++i){
        for(int j=0; j<n; ++j){
            int chk = i-whysohard[j];
            if(chk < 0) continue;

            if(track[chk] ){
                track[i] = 1;
            }
        }
    }

    bool has = false;

    for(int i=1; i<=r; ++i) if(!track[i]) cout << i << endll, has = true;

    if(!has) cout << "Not found";

    return 0;
}
