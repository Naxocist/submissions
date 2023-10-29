#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ar[n][2], cnt[n][2], diff[n][2], sumab[n], mxx[n], mxy = 0; 
    for(int i=0; i<n; ++i) {
        scanf("%d%d", &ar[i][0], &ar[i][1]);
        cnt[i][0] = 0;
        cnt[i][1] = 0;
        // base 1
        ar[i][0]++;
        ar[i][1]++;
        mxy = (ar[i][0]+ar[i][1]+2 > mxy) ? ar[i][0]+ar[i][1]+2 : mxy;
        mxx[i] = (ar[i][0]>ar[i][1]) ? ar[i][0] : ar[i][1];
        mxx[i] = (mxx[i]-1) * 2 + 3;
        sumab[i] = ar[i][0] + ar[i][1]+2;
        diff[i][0] = ar[i][1] - ar[i][0];
        diff[i][1] = ar[i][0] - ar[i][1];
    }

    for(int ry=mxy; ry>=1; --ry){
        for(int i=0; i<n; ++i){
            if(ry>sumab[i]){
                for(int j=0;j<mxx[i];j++) printf(" ");
                continue;
            }
            int y, isBelow = (ry>ar[i][1]+1) ? 0 : 1;
            
            if(isBelow==0) y = ry - (ar[i][1]+1); 
            else y = ry;
            
            for(int k=0;k<diff[i][isBelow];k++) printf(" ");
            
            if(y <= ar[i][isBelow]) printf("|");
            else printf(" ");
            
            for(int j=1; j<=ar[i][isBelow]; ++j){
                if(y == ar[i][isBelow] && j == ar[i][isBelow]) printf("^");
                else if(j == y) printf("/");
                else if(j > y) printf("%c", 'A' + (cnt[i][isBelow]++ % 26));
                else if(ar[i][isBelow]+1 == y) printf("_");
                else printf(" ");
            }

            for(int j=ar[i][isBelow]-1; j>=1; --j){
                if(j == y) printf("\\");
                else if(j > y) printf("%c", 'A' + (cnt[i][isBelow]++ % 26));
                else if(ar[i][isBelow]+1 == y) printf("_");
                else printf(" ");
            }
            
            if(y <= ar[i][isBelow])printf("|");
            else printf(" ");
            for(int k=0;k<diff[i][isBelow];k++) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*
3
2 5   
2 8
3 7

2
2 3
4 5
*/