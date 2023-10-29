#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 3;

int ok[1 << 20];
bool res[101];

int main() {

    int x, y; scanf("%d%d", &x, &y) ;

    for(int i=0; i<x; ++i) {
        char s[30] ; scanf("%s", s);

        int b = 0;
        for(int j=0; j<y; ++j, b<<=1) {
            if(s[j] == '1') b |= 1;
        }

        ok[b] = i;
    }    

    int q; scanf("%d", &q);
    while(q--) {
        int n; scanf("%d", &n);
        char t[N]; scanf("%s", t);
        
        int b = 0;
        bool chk = 1;
        for(int i=0; i<n; ++i, b<<=1) {
            if(t[i] == '1') b |= 1;
            
            if(i > y-1) {
                if(ok[b]) res[ok[b]] = 1, chk = 0;

                b &= ~(1 << y);
            }
        }

        if(chk) printf("OK") ;
        for(int i=0; i<100; ++i) {
            if(res[i] ) printf("%d ", i+1);
        }

        printf("\n") ;
    }
    // int x, y; cin >> x >> y;

    // vector<string> pat;
    // for(int i=0; i<x; ++i) {
    //     string s; cin >> s;
    //     int z = 0;
    //     for(auto c : s) {
    //         z  = (z << 1) + (c-'0');
    //     }
    //     cout << "HASH: " << z << endl;;
    //     int a = 0;
    //     for(int b=1; b<s.size();) {
    //         if(s[a] == s[b]) {
    //             ar[i][b] = a+1;
    //             a++; b++;
    //         }else {
    //             if(a) a = ar[i][a-1];
    //             else {
    //                 ar[i][b] = 0;
    //                 b++;
    //             }
    //         }
    //     }
    //     pat.push_back(s);
    // }

    // int q; cin >> q;

    // while(q--) {
    //     int n; cin >> n;
    //     string t; cin >> t;
    //     bool c = 1;

    //     for(int i=0; i<x; ++i) {
    //         string p = pat[i];
    //         int a = 0, b = 0;
    //         while(a < t.size() && b < p.size()) {
    //             if(t[a] == p[b]) {
    //                 a++; b++;                    
    //                 if(b == p.size()) {
    //                     cout << i+1 << ' '; c = 0; break;
    //                 }
    //             }else {
    //                 if(b) b = ar[i][b-1];
    //                 else a++;
    //             }
    //         }

    //     }

    //     if(c) {
    //         cout << "OK";
    //     }
    //     cout << '\n';
        
    // }
    return 0;
}