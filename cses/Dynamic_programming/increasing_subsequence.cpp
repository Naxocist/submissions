#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int n; scanf("%d", &n);
    vector<int> v;
    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x);
        auto t = lower_bound(v.begin(), v.end(), x);
        if(t == v.end()) {
            v.push_back(x);
        }else {
            *t = x;
        }
    }
    
    printf("%d", v.size());
    return 0;
}
