#include <bits/stdc++.h>
using namespace std;


const int N = 1005;
int dsu[N], sz[N];
int n, k;

double dist(double x, double y, double a, double b) {
    return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}


int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    int x = par(u), y = par(v);
    if(x == y) return ;
    if(sz[x] > sz[y]) swap(x, y);
    dsu[x] = y;
    k--;
    sz[y] += sz[x];
    
}

pair<double, double> ar[1005];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);
    int t; scanf("%d", &t);

    while(t--){
        int d;
        scanf("%d%d", &n, &d);
        for(int i=0; i<n; ++i) dsu[i] = i, sz[i] = 1;
        k = n;

        for(int i=0; i<n; ++i) {
            double x, y; cin >> ar[i].first >> ar[i].second;
            for(int j=0; j<i; ++j) {
                if(dist(ar[i].first, ar[i].second, ar[j].first , ar[j].second) < d) {
                    un(i, j);
                } 
            }
        }

        cout << k << '\n';
    }
    return 0;
}