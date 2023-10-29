#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int fw[N], n, q;

void update(int i, int x) {
    for(; i<=n; i+=i&-i) fw[i] += x;
    return ;
}

int sum(int i) {
    int s = 0;
    for(; i>0; i-=i&-i) s += fw[i];
    return s;
}

int lw_bound(int x) {

    int sum = 0, base = 0;

    for(int i=log2(n); i>=0; --i) {
        if(base + (1<<i) <= n && sum + fw[base + (1<<i)] < x) {
            sum += fw[base + (1<<i)];
            base += (1 << i);
        }
    }
    return base + 1;
    // int l = 1, r = n;
    // while(l < r) {
    //     int md = l + (r - l)/2;
    //     if(sum(md) >= x) r = md;
    //     else l = md + 1;
    // }

    // return l;
}


int main() {

    scanf("%d%d", &n, &q);

    for(int i=1; i<=n; ++i) {
        int x; scanf("%d", &x);
        update(x, 1);
    }

    while(q--) {
        int o; scanf("%d", &o);

        if(o > 0) update(o, 1);
        else {
            o *= -1;
            int t = lw_bound(o);
            update(t, -1);
        }
    }

    
    int l = 1, r = n;
    while(l < r) {
        int md = l + (r - l)/2;

        if(sum(md) > 0) r = md;
        else l = md + 1; 
    }
    if(l == n && sum(n) == 0) printf("0");
    else printf("%d", l);
    return 0;
}

/*
5 5
1 1 2 2 7
-2 
-2
9
10
11
*/