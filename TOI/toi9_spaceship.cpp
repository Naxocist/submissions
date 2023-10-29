#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
bool ch[13];
int res = 1e9, m;

struct point {
    int x, y, z, a, b, c;
} p[13];



int cal(point l, point r) {
    return (l.x - r.x)*(l.x - r.x) + (l.y - r.y)*(l.y - r.y) + (l.z - r.z)*(l.z - r.z);
}

void f(int rs, int a, int b, int c, point s) {

    if(a <= 0 && b <= 0 && c <= 0) {
        res = min(res, rs);
        return ;
    }

  
    for(int i=0; i<m; ++i) {
        if(ch[i]) continue ;
        ch[i] = 1;
        f(rs + cal(s, p[i]), a-p[i].a, b-p[i].b, c-p[i].c, p[i]);
        ch[i] = 0;
    }

    return ;
}

int main() {
    int n;
    point s; 
    scanf("%d%d%d%d%d", &n, &s.x, &s.y, &s.z, &m);
    for(int i=0; i<m; ++i) {
        scanf("%d%d%d%d%d%d", &p[i].x, &p[i].y, &p[i].z, &p[i].a, &p[i].b, &p[i].c);
    }

    f(0, n, n, n, s);

    printf("%d", res);
    return 0;
}

/*
1
0 0 0
2
10 0 0
2 5 7
0 10 0
0 3 9

5
0 0 0
5
60 34 56
0 5 7
90 41 92
1 7 8
24 61 81
6 8 8
41 86 70
5 6 7
46 97 85
9 2 4
*/