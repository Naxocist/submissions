#include <bits/stdc++.h>
using namespace std;

const int N = 20;
bool p[N], no;
vector<vector<int>> v[2];

bool chk2(int t, int i) {
    
    for(int x : v[t][i]) {
        bool b = p[abs(x)];
        if(x < 0) b = !b;
        if(b) return 1;
    }
    return 0;
}

bool chk(int t) {
    for(int i=0; i<v[t].size(); ++i) {
        if(!chk2(t, i)) return 0;
    }

    return 1;
}

void f(int i) {
    if(i == 17) {
        if(chk(0) && !chk(1)) no = 1; // T -> F
        return ;
    }
    
    p[i] = 1;
    f(i+1);
    p[i] = 0;
    f(i+1);
}


int main() {
    cout.tie(nullptr); cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int k; cin >> k;
    while(k--) {
        v[0].clear(); v[1].clear(); no = 0;
        int a[2]; cin >> a[0] >> a[1];
        for(int i=0; i<2; ++i) {
            while(a[i]--) {
                v[i].push_back({});
                int x; cin >> x;
                while(x--) {
                    string s; cin >> s;
                    v[i].back().push_back((s[1]-'a'+1) * (s[0] == '+' ? 1 : -1));
                }
            }
        }
        f(1);
        cout << (no ? "NO\n" : "YES\n");
        
    }
    return 0;
}
/*
2
3 1
2 -a +b
2 -b +c
1 -c
1 –a
1 1
1 +b
1 -a
*/