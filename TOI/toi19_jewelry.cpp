#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 10;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s = '*' + s;

    vector<int> last_pos(MAXN);

    ll res = 0, sum = 0, crr = 0;
    for (int l=1; l<=n; ) {

        if (s[l] == 'T') {
            int r = l;
            while(r < n and s[r+1] == 'T') r++;

            for(int i=l; i<=r; ++i) {
                int len = i-l+1;
                sum += i - last_pos[len];
                last_pos[len] = r-len+1;
                res += sum;
            }
            l = r + 1;
        } else {
            res += sum;
            l ++;
        }
    }
    cout << res;
}