#include <stdio.h>

int main() {

    int n, m; scanf("%d%d", &n, &m);

    char spiral[n][m];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            spiral[i][j] = ' ';
        }
    }


    int number = 0, r = 0, c = m-1, isreverse = 1;

    while(r < n) {
        spiral[r][c] = number + '0';

        r++;
        number++;
        number %= 10;
        if(c == 0) isreverse = 0;
        else if(c == m-1) isreverse = 1;

        if(isreverse) c--;
        else c++;
    }

    int alphabet = 0;
    r = 0, c = 0, isreverse = 0;

    while(r < n) {
        spiral[r][c] = 'A' + alphabet;

        r++; 
        alphabet++;
        alphabet %= 26;
        if(c == 0) isreverse = 0;
        else if(c == m-1) isreverse = 1;

        if(isreverse) c--;
        else c++;

    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            printf("%c", spiral[i][j]);
        }
        printf("\n");
    }
    return 0;
}