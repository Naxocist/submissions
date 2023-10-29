#include <bits/stdc++.h>
using namespace std;


int div(int n) {
    int x = 999 / n;
    return n * (x + 1) * x/2;
}

int main() {

    // int r = 0;
    // for(int i=1; i<1000; ++i) {
    //     if(i % 3 == 0 || i % 5 == 0) r+=i;
    // }
    // printf("%d", r);

    printf("%d", div(3) + div(5) - div(15));
    return 0;
}