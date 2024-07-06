#include <stdio.h>

int main() {

    int n, m; scanf("%d%d", &n, &m);

    int numcol = m-1, alphacol = 0, number = 0, alphabet = 0, numreverse = 1, alphareverse = 0;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            
            if(j == alphacol) {
                printf("%c", 'A' + alphabet);
                alphabet++;
                alphabet %= 26;
                if(j == numcol) {
                    number++;
                    number %= 10;
                }
            }   
            else if(j == numcol) {
                printf("%d", number); 
                number++;
                number %= 10;
            }else {
                printf(" ");
            }

        }
        if(i != 0 && i % (m-1) == 0) {
            numreverse = !numreverse;
            alphareverse = !alphareverse;
        }
        
        if(numreverse) numcol--;
        else numcol++;

        if(alphareverse) alphacol--;
        else alphacol++;

        printf("\n");
    }
    return 0;
}
