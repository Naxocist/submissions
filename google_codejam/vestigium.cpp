#include <bits/stdc++.h>
using namespace std;

const int N = 105;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; scanf("%d", &t);

    for(int i=1; i<=t; ++i){
        printf("Case #%d: ", i);
        int ar[N][N], n; scanf("%d", &n);

        int k = 0, r = 0, c = 0;

        for(int j=0; j<n; ++j){
            for(int h=0; h<n; ++h) {
                int x; scanf("%d", &x);
                ar[j][h] = x;
                if(j == h) k += x;
            }
        }

        for(int j=0; j<n; ++j){
            unordered_map<int, int> cr, cc;
            bool br=false, bc=false;
            for(int h=0; h<n; ++h) {
                if(cc.find(ar[h][j]) != cc.end() && !bc) c++, bc=true;
                if(cr.find(ar[j][h]) != cr.end() && !br) r++, br=true;
                cc[ar[h][j]] += 1;
                cr[ar[j][h]] += 1;
            }
        }

        printf("%d %d %d\n", k, r, c);
    }    
    return 0;
}
