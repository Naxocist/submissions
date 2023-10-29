#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

int a[25][25], chk[25][25], ans = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int x, y, a, b; cin >> x >> y >> a >> b;

    queue<pair<int, int>> q;
    queue<int> r;
    q.push({x, y});
   
    
    chk[x][y] = 1;
    int m1[] = {1, -1};
    int m2[] = {2, -2};
    int curr = 0;
    r.push(curr);
    while(!q.empty()){
        int o = q.front().first, l = q.front().second;
        int round = r.front();
        r.pop();
        q.pop();

        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                int h = o + m1[i], k = l + m2[j];
                if(h < 0 || k >= n || k<0 || h >=n) continue;

                if(h == a && k == b){
                    cout << round+1 ;
                    return 0;
                    
                }

                if(chk[h][k] == 0){
                    q.push({h ,k}); r.push(round+1);
                    chk[h][k] = 1;
                }

                h = o + m2[i], k = l + m1[j];
                if(chk[h][k] == 0){
                    q.push({h, k});r.push(round+1);
                    chk[h][k] = 1;
                }

            }
        }
    }

    return 0;
}
