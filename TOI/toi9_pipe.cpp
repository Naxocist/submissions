#include <bits/stdc++.h>
using namespace std;


const int N = 15005;
int x[N], y[N], dist[N];
bool vis[N];

int main() {
    // freopen("input.in", "r", stdin);
    
    int n, k; scanf("%d%d", &n, &k);
    
    for(int i=0; i<n; ++i){
        scanf("%d%d", &x[i], &y[i]);
        dist[i] = 2e9;
    }

    vector<int> ans;
    vis[0] = 1;
    int a = x[0], b = y[0];

    for(int i=1; i<n; ++i){
        int idx, mn = 2e9;

        for(int j=1; j<n; ++j){
            if(vis[j]) continue;
            dist[j] = min(dist[j], abs(a - x[j]) + abs(b - y[j]));

            if(dist[j] < mn){
                mn = dist[j];
                idx = j;
            }
        }

        vis[idx] = 1;
        a = x[idx], b = y[idx]; 
        ans.push_back(mn);
    }

    sort(ans.rbegin(), ans.rend());

    int s = 0;
    for(int i=k-1; i < ans.size(); ++i) s += ans[i];

    cout << s;
}
