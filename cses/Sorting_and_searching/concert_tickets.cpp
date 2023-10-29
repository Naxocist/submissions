#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n, m ;scanf("%d%d", &n, &m);
 
    multiset<int> s;
    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x);
        s.insert(x);
    }
 
    while(m--) {
        int x; scanf("%d", &x);
        auto t = s.upper_bound(x);
 
    
        if(t == s.begin()) printf("-1\n");
        else {
            printf("%d\n", *(--t));
            s.erase(t);
        }
    }
    return 0;
}
