#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;  cin >> t;
    while(t--) {
        int n; cin >> n;
        int x = 0, y = 0;
        while(n--) {
            int s; cin >> s;
            if(s % 2) x += s;
            else y += s;
        }

        if(y > x) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
    return 0;
}