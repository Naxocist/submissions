#include <bits/stdc++.h>
using namespace std;

int main() {

    // int x = 997002;
    // for(int k=0; k<3; ++k) {
    //     int first = (x/(int)pow(10, 5 - k)) % 10, last = (x / (int)pow(10, k)) % 10;

    //     printf("%d %d\n", first ,last);
    // }

    // return 0;

    // # find the largest palindrome made from product of 3 digit number

    int res = 0, operation = 0;
    for(int i=999; i>=111; --i) {
        int j, dj;
        if(i % 11 == 0) { // improvement using math*
            j = i;
            dj = 1;
        }else {
            j = 990;
            dj = 11;
        }
        for(; j>=111; j -= dj) {
            int x = i * j;
            if(x <= res) break ; // big improvement **
            operation ++ ;
            for(int k=0; k<3; ++k) {
                int first = (x/(int)pow(10, 5 - k)) % 10, last = (x / (int)pow(10, k)) % 10;

                if(first != last) goto g;
            }
            res = x;
            g:;
        }
    }

    printf("%d %d", res, operation);
    return 0;
}