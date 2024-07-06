#include <stdio.h>
int main() {

    int n; scanf("%d", &n) ;
    int ar[1500][1500];

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) ar[i][j] = '*';
    } 

    int r = 2, w = n;
    while(r <= n/2) {
        for(int i=r; i<w; ++i) {
            for(int j=r; j<w; ++j) {
                if(i == r || j == r || i == w-1 || j == w-1) ar[i][j] = '-';
            }
        }
        r += 2;
        w -= 2;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) printf("%c", ar[i][j]);

        printf("\n");
    }
    return 0;
}