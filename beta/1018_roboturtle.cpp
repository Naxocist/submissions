#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);
    int d = 1, i = 0, j = 0 ;
    while(n--) {
        char c,t; int x; scanf(" %c%c%d", &c,&t,&x);
        
        if(c == 'L') {
            d --;
        }else if(c == 'R'){
            d ++;   
        }else if(c == 'B') {
            d += 2; 
        }

        if(d < 0) d = 3;
        d %= 4;

        if(d == 1) i += x;
        else if(d == 2) j -= x;
        else if(d == 3) i -= x;
        else j += x;
        
        int lim = 5e4;
        if(i >= lim || i <= -lim || j >= lim || j <= -lim) {
            cout << "DEAD"; return 0;
        }
    }

    char res[] = {'N', 'E', 'S', 'W'};
    cout << i << ' ' << j << '\n' << res[d];
    return 0;
}