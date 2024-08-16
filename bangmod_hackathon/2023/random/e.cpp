#include <bits/stdc++.h>
using namespace std;

int f(char c) {
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

char revf(int x) {
    if(x <= 9) return x+'0';
    return 'A'+x-10;
}

using ll = long long;

int main() {
    int n; cin >> n;
    if(n > 3 || n < 1) {
        cout << "error"; return 0;
    }

    if(n == 1) {

    }
    return 0;
}

