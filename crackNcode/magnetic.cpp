#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 3;
int dsu[N];
int n, m, res;

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    int x = par(u), y = par(v);
    if(x == y) return ;
    dsu[x] = y; res--;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> m;
    string s; cin >> s;

    for(int i=0; i<n; ++i) dsu[i] = i;
    res = n;
    for(int i=0; i<n; ++i) {
        if(s[i] == '1') {
            int k = 1;
            while(k <= m && s[(i+k)%n] != '1') {
                un(i, (i+k)%n);
                k++;
            }
            k = 1;
            while(k <= m && s[(i-k+n)%n] != '1') {
                un(i, (i-k+n)%n);
                k++;
            }
        }
    }
    printf("%d", res);

    return 0;
}