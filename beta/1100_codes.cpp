#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int N = 13;
int a[3][N], b[3][N][N], c[1003];

int main() {

    int n; scanf("%d", &n);

    ll res = 0;
    while(n--) {
        int s; scanf("%d", &s);
        int x = s%10, y = (s/10)%10, z = s/100;

        res += (ll) (a[0][x] + a[1][y] + a[2][z] - b[0][x][y] - b[1][x][z] - b[2][y][z] + c[s]);

        a[0][x] ++, a[1][y] ++, a[2][z] ++, b[0][x][y] ++, b[1][x][z] ++, b[2][y][z] ++, c[s] ++;
    }

    printf("%lld", res);
    return 0;
}