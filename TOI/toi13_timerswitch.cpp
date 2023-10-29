#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

bool pattern(string &s, int k){

    for(int i=s.size()-1, j=k-1; i>=0; --i, --j){
        if(s[i] != s[j]) return 0;
        if(j == 0) j = k;
    }

    return 1;
}

int main() {
    // freopen("input.in", "r", stdin);

    int n; scanf("%d", &n);
    string s; cin >> s;

    for(int i=1; i<n; ++i){ // check pattern length i
        if(n % i) continue;
        
        if(pattern(s, i)) {
            printf("%d", i);
            return 0;
        }
    }

    printf("%d", n);
}
