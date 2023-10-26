#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;


int main() {
    // freopen("input.in", "r", stdin);

    int t = 20;
    while(t--){
        int n; scanf("%d", &n);
        string s; cin >> s;
        if(s == "02"){
            printf("yes\n");
            continue;
        }

        int z = 0, c = 0;
        for(int i=0; i<n; ++i) {
            if(s[i] == '0'){
                z++;
                if(i > 1) c++;
            }
        }

        if(s[0] != '0' || z == 0){
            printf("no\n");
            continue;
        }

        if(s[0] == '0' && c == 0){
            printf("%s\n", (s[1] == '2' ? "yes" : "no")); 
            continue;
        }

        if(z == n){
            printf("%s\n", (z&1 ? "yes" : "no")); 
            continue;
        }

        printf("yes\n");
    }
    
    return 0;
}
