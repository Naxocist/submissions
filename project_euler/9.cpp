#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 1000;
    for(int b=1; b<n; ++b) {
        int x = (1000 * (500 - b)), y = 1000 - b;
        if(x % y || x <= 0) continue ;

        int a = x / y;
        if(a > b) continue ;
        int c = 1000 - a - b;
        printf("%d %d %d\n", a, b, c);
        printf("%d", a * b * c);
    }
    return 0;
}