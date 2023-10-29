#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
 
const int N = 1e9 + 10;
bitset<N> bs;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        bs[x] = true;
    }
 
    cout << bs.count();
    return 0;
}
