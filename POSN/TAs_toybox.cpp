#include <stdio.h>

int main() {

    int n; scanf("%d", &n);
    int ar[n], cnt[n], mx = 0;

    for(int i=0; i<n; ++i) {
        scanf("%d", &ar[i]);
        cnt[i] = 0;
        ar[i]++;
        mx = (ar[i] > mx ? ar[i] : mx);
    }

    for(int y=mx+1; y>=1; --y) {
        
        for(int i=0; i<n; ++i) {
            if(y <= ar[i]) printf("|");
            else printf(" ");
            for(int j=1; j<=ar[i]; ++j) {
                if(y == ar[i] && j == ar[i]) printf("^");
                else if(j == y) printf("/");
                else if(j > y) printf("%c", 'A' + (cnt[i]++ % 26));
                else if(ar[i]+1 == y) printf("_");
                else printf(" ");
            }

            for(int j=ar[i]-1; j>=1; --j) {
                if(j == y) printf("\\");
                else if(j > y) printf("%c", 'A' + (cnt[i]++ % 26));
                else if(ar[i]+1 == y) printf("_");
                else printf(" ");
            }

            if(y <= ar[i]) printf("|");
            else printf(" ");
        }

        printf("\n");
    }
    return 0;
}