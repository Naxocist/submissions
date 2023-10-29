#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using T = tuple<int, int, int>;
const int N = 1e6 + 3;
int color[N];

struct paint {
    int x, h, o;
    paint(int x, int h, int o): x(x), h(h), o(o) {}
    bool operator< (const paint other)const {
        return x < other.x;
    }
};

int sum(int i) {
    int s = 0;
    for(;i>0;i-=i&-i) s += color[i];
    
    return s;
}

void update(int k, int x) {
    for(int i=1;i<=N;i+=i&-i) color[i] += x;
    for(int i=k+1;i<=N;i+=i&-i) color[i] -= x;
    return ;
}

int bs(int t) {
    int l = 1, r = 1e6;

    while(l < r) {
        int md = l + (r - l)/2;
        // printf("%d %d\n", l, r);
        
        if(sum(md) >= t) l = md + 1;
        else r = md;
    }

    return l + 1;
}



int main() {

    int n, t; scanf("%d%d", &n, &t);

    vector<paint> v;
    vector<int> p;
    while(n--) {
        int s, h, w, o; scanf("%d%d%d%d", &s, &h, &w, &o);
        v.emplace_back(s, h, o);
        v.emplace_back(s+w, h, -o);
    }

    sort(v.begin(), v.end());

    int res = 0;

    for(int i=0; i<v.size();) {
        int j = i;
        for(; j<v.size() && v[i].x == v[j].x; ++j) {
            update(v[j].h, v[j].o);
        }
        res += (bs(t) - bs(t+1)) * (v[j].x - v[i].x);

        i = j;
    }

    printf("%d", res);
    return 0;
}