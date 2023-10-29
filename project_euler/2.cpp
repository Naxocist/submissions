#include <bits/stdc++.h>
using namespace std;

int main() {

    // int a = 1, b = 2, s = 0;
    // while(b <= 4e6) {
    //     if(b % 2 == 0) s += b;
    //     int t = b;
    //     b += a;
    //     a = t;
    // }

    int a = 1, b = 2, c = 3, s = 0;
    while(b <= 4e6) {
        s += b;
        a = b + c;
        b = c + a;
        c = b + a;
    }

    printf("%d", s);
    return 0;
}