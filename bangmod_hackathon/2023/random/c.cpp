#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    string ss; cin >> ss;
    int n = ss[0] - '0', m = ss[2] - '0';
    cout << n << ' ' << m << endl;
    int x[n][m];
    string s;
    int i = 0, j = 0;
    while(cin >> s) {

        for(char c : s) {
            if(c == ';') goto tt;
            if(isdigit(c)) {
                x[i][j] = c - '0';
                j++;
                if(j == m) i++;
                j%=m;
            }
        }
    }
    tt:
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout << x[i][j] << endl;
        }
    }

    return 0;
}
