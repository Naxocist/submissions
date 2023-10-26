#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 2e6 + 3;
int ar[N];

int main() {
    // freopen("input.in", "r", stdin);
    int n; scanf("%d", &n);
    int l, r;
    l = r = 0;
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]), r = max(r, ar[i]);
    
    int ans = INT_MAX;
    while(l <= r){ // binary search on capacity
        int md = l + (r - l)/2;
        bool ok = 1;
        vector<int> v;

        for(int i=0; i<n; ++i) if(ar[i] > md) v.push_back(ar[i]);
        for(int i=0; i<v.size(); i+=2){
            if(v[i] != v[i+1]){
                ok = 0;
                break;
            }
        }

        if(ok){
            ans = min(ans, md);
            r = md - 1;
        }else l = md + 1;
    }

    printf("%d", ans);
    return 0;
}
