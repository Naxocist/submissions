#include <stdio.h>

int main() {

    int n; scanf("%d", &n);

    int m = n/2, c = n%2;
    
    for(int i=0; i<m; ++i) { // top of the pattern

        int s = 1;
        for(int j=0; j<m; ++j) { // top left
            
            if(s) printf("*");
            else printf("-");

            if(j < i) s = !s;
        }
        if(c) printf("%c", s ? '*' : '-');
        for(int j=m-1; j>=0; --j) { // top right
            
            if(s) printf("*");
            else printf("-");

            if(j <= i) s = !s;
        }
        printf("\n");
    }
    
    if(c) { 
        for(int i=0; i<n; ++i) {
            printf("%c", i%2 ? '-' : '*');
        }
        printf("\n") ;
    }

    for(int i=m-1; i>=0; --i) { // bottom of the pattern

        int s = 1;
        for(int j=0; j<m; ++j) { // bottom left
            
            if(s) printf("*");
            else printf("-");

            if(j < i) s = !s;
        }
        if(c) printf("%c", s ? '*' : '-');
        for(int j=m-1; j>=0; --j) { // bottom right
            
            if(s) printf("*");
            else printf("-");

            if(j <= i) s = !s;
        }
        printf("\n");
    }
    return 0;
}
