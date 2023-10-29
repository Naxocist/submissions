    #include <bits/stdc++.h>
    using namespace std;

    char ar[105][105];
    int main() {
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        int n, m, k, x = 0, y = 0; cin >> n >> m >> k;

        for(int i=0; i<n; ++i) {
            string t; cin >> t;
            for(int j=0; j<m; ++j) ar[i][j] = t[j];
        }

        string s; cin >> s;
        for(char c  : s) {
            if(c == 'U') x--;
            else if(c == 'D') x++;
            else if(c == 'L') y--;
            else y++;
        }

        cout << ar[x][y];
        return 0;
    }