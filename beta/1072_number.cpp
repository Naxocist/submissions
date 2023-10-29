#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 3;
int ar[N];

int k = 1, f = 0, n, q;
int h(int x) {
    return (f + k*x + n) % n;
}

int main() {
 
    scanf("%d%d", &n, &q);

    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);

    
    while(q--) {
        char c; scanf(" %c", &c);
        int x, y;
        if(c == 'a' || c == 'b') scanf("%d%d", &x, &y);
        else scanf("%d", &x);
        
        if(c == 'a') {
            x--; y--;
            swap(ar[h(x)], ar[h(y)]);
        }
        if(c == 'b') {
            x--;
            ar[h(x)] = y;
        }
        if(c == 'c') {
            x--;
            f = h(x);
            k *= -1;
        }
        if(c == 'q') {
            x--;
            printf("%d\n", ar[h(x)]);
        }
    }
    return 0;
}

/*
7 5
0 1 2 3 4 5 6
q 1
c 4
q 1
c 2
q 1
*/