#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
using ll = long long;
 
struct pt {
    ll x, y;
};
 
bool cmp (pt a, pt b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
 
bool cw(pt a, pt b, pt c) { // clockwise
    return ((b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y)) > 0;
}   
 
bool ccw(pt a, pt b, pt c) { // counter clockwise   
    return ((b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y)) < 0;
}
 
void convex(vector<pt> &p) {
    int n = p.size();
 
    sort(begin(p), end(p), cmp);
    pt st = p[0], ed = p.back();
    vector<pt> top = {st}, down = {st};
    for(int i=1; i<n; ++i) {
        // top
            while(top.size() >= 2 && ccw(top[top.size()-2], top[top.size()-1], p[i])) top.pop_back();
            top.push_back(p[i]);

        // down
            while(down.size() >= 2 && cw(down[down.size()-2], down[down.size()-1], p[i])) down.pop_back();
            down.push_back(p[i]);
    }
    p.clear();
 
    for(pt e : top) p.push_back(e);
    for(int i=0; i<down.size(); ++i) {
        if(i == 0 || i == down.size()-1) continue ;
        p.push_back(down[i]);
    }
    return ;
}
 
int main() {
 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    vector<pt> p(n);
    for(int i=0; i<n; ++i) cin >> p[i].x >> p[i].y;
    convex(p);
    cout << p.size() << ln;
    for(pt e : p) cout << e.x << ' ' << e.y << ln;
    return 0;
}