
#include <bits/stdc++.h>
using namespace std;

#define deb 0

void acc(string s) {
    cout << s + "(acc)" << '\n';
}

void wd(string s) {
    cout << s + "(w/d)" << '\n';
}

void no() {
    cout << "-(-) " << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    if(deb) {
        freopen("./in.txt", "r", stdin);
        freopen("./out.txt", "w", stdout);
    }

    int n, m; cin >> n >> m;
    vector<string> a, b;
    for(int i=0; i<n; ++i) {
        string s; cin >> s;
        a.push_back(a);
    }
    for(int i=0; i<m; ++i) {
        string s; cin >> s;
        a.push_back(b);
    }

    int x = n, y = m;
    int i = 0, j = 0;
    while(i < n and j < m) {
        int q = 3;
        while(q--) {
            if(x > y/2) {
            x--;
                cout << a[i++]
            }
        }
    }
    return 0;
}
