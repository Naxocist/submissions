#include <bits/stdc++.h>
using namespace std;

int f(char c) {
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

char revf(ll x) {
    if(x <= 9) return x+'0';
    return 'A'+x-10;
}

using ll = long long;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    ll a, b; cin >> a >> b;

    if(a < 2 || b < 2 || a > 36 || b > 36) {
        cout << "error"; return 0;
    }

    for(char c : s) {
        if((isalpha(c) and islower(c)) || f(c) >= a || (!isalpha(c) and !isdigit(c))) {
            cout << "error"; return 0;
        }
    }

    ll t = 0, x = 1;
    for(char c : s) {
        t += f(c)*x;
        x *= a;
    }
    string res;
    while(t) {
        res += revf(t%b);
        t/=b;
    }
    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
