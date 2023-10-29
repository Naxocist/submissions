#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;  cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> v(100, -1);
        for(int i=0; i<s.size(); ++i) {
            int x = s[i] - 'a';
            if(v[x] == -1) v[x] = i;
            else if(v[x] % 2 != i % 2) {
                cout << "NO";
                goto g;
            }
        }
        cout << "YES";
        g:;
        cout << '\n';
    }
    return 0;
}