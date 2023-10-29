#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> pos[10];

int ub(vector<int> &v, int x) {
    auto t = upper_bound(v.begin(), v.end(), x);
    if(t == v.end()) return 0;
    return *t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;


    for(int i=0; i<s.size(); ++i) {
        char c = s[i];
        if(c == 'c') pos[1].pb(i+1);
        else if(c == 'o') pos[2].pb(i+1);
        else if(c == 'd') pos[3].pb(i+1);
        else if(c == 'e') pos[4].pb(i+1);
        else if(c == 'u') pos[5].pb(i+1);
        else pos[6].pb(i+1);
    }

    int l = 0, r = 0, mn = 1e9;
    for(int x : pos[1]) {
        int next = ub(pos[2], x);if(next == 0) continue ; // o
        next = ub(pos[3], next); if(next == 0) continue ; // d
        next = ub(pos[4], next); if(next == 0) continue ; // e
        next = ub(pos[1], next); if(next == 0) continue ; // c
        next = ub(pos[5], next); if(next == 0) continue ; // u
        next = ub(pos[6], next); if(next == 0) continue ; // b
        next = ub(pos[4], next); if(next == 0) continue ; // e

        if(next - x < mn) {
            mn = next - x;
            l = x, r = next;
        }
   
    }
    
    if(mn == 1e9) printf("-1");
    else printf("%d %d", l, r);
    return 0;
}

