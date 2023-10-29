#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


void printa(int a[], int n){
    for(int i=0; i<n; ++i) cout << a[i] << ' ';
}


const int N = 501;
int a[N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];

    for(int i=1; i<n; ++i){

        int curr=i;
        for(int j=i-1; j>=0; --j){
            if(a[j] > a[curr]) swap(a[j], a[curr]);
            curr--;
        }


        if(i == n-1) break;
        for(int j=0; j<n; ++j){
            int x; cin >> x;
            if(x != a[j]) {
                printa(a, n);
                return 0;
            }
        }

    }

    printa(a, n);

    return 0;

}

/*
10
79 100 36 49 11 99 40 73 16 76
79 100 36 49 11 99 40 73 16 76
36 49 79 100 11 99 40 73 16 76
11 36 49 79 100 99 40 73 16 76
11 36 49 79 99 100 40 73 16 76
11 36 40 49 79 99 100 73 16 76
11 36 40 49 73 79 99 100 16 76
11 16 36 40 49 73 79 99 100 76
11 16 36 40 49 73 76 79 99 100

4
24 98 74 96
24 98 74 96
24 74 96 98
*/
