#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using ll = long long;
const int N = 15;
int r, c;
char ar[N][N];


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // 0 45 90 135 180 225 270 315 360
    cin >> r >> c;

    for(int i=0; i<r; ++i){
        string s; cin >> s;
        for(int j=0; j<c; ++j) ar[i][j] = s[j];
    }

    int k; cin >> k;
    int d = r + c - 1;

    if(k == 0 || k == 360){

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j) cout << ar[i][j];
            cout << '\n';
        }

    }else if(k == 45){
        int i = 0, j = 0, si = r-1;
        
        bool ok = 0;
        while(d--){
            for(int h=0; h<si; ++h) cout << ' ';
            for(int h=i, k=j; h>=0 && k<=c; --h, ++k) {
                if(h != i) cout << ' ';
                cout  << ar[h][k];
            }

            if(i == r-1) ok = 1;
            if(ok) j++, si++;
            else i++, si--;

            cout << '\n';
        }

    }else if(k == 90){
        
        for(int j=0; j<c; ++j){
            for(int i=r-1; i>=0; --i) cout << ar[i][j];
            cout << '\n';
        }

    }else if(k == 135){
        int i = r-1, j = 0, si = c-1;
        
        bool ok = 0;
        while(d--){
            for(int h=0; h<si; ++h) cout << ' ';
            for(int h=i, k=j; h>=0 && k>=0; --h, --k) {
                if(h != i) cout << ' ';
                cout  << ar[h][k];
            }

            if(j == c-1) ok = 1;
            if(ok) i--, si++;
            else j++, si--;

            cout << '\n';
        }
    }else if(k == 180){
        for(int i=r-1; i>=0; --i){
            for(int j=c-1; j>=0; --j) cout << ar[i][j];
            cout << '\n';
        }
    }else if(k == 225){
        int i = r-1, j = c-1, si = r-1;
        
        bool ok = 0;
        while(d--){
            for(int h=0; h<si; ++h) cout << ' ';
            for(int h=i, k=j; h<=r && k>=0; ++h, --k) {
                if(h != i) cout << ' ';
                cout  << ar[h][k];
            }

            if(i == 0) ok = 1;
            if(ok) j--, si++;
            else i--, si--;

            cout << '\n';
        }

    }else if(k == 270){

        for(int j=c-1; j>=0; --j){
            for(int i=0; i<r; ++i) cout << ar[i][j];
            cout << '\n';
        }

    }else if(k == 315){

        int i = 0, j = c-1, si = c-1;
        
        bool ok = 0;
        while(d--){
            for(int h=0; h<si; ++h) cout << ' ';
            for(int h=i, k=j; h<r && k<c; ++h, ++k) {
                if(h != i) cout << ' ';
                cout  << ar[h][k];
            }

            if(j == 0) ok = 1;
            if(ok) i++, si++;
            else j--, si--;

            cout << '\n';
        }
    }

    return 0;
}

/*
5 5
abcde
bcdef
cdefg
defgh
efghi

*/