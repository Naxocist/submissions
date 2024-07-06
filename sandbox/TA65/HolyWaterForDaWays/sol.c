#include <stdio.h>

int main() {

    int n; scanf("%d", &n);

    long long int ar[n];
    for(int i=0; i<n; ++i) {
        scanf("%lld", &ar[i]);
    }

    long long int mx = -1e9;
    int woodleft = -1, woodright = -1;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            long long int k, water;

            if(ar[i] < ar[j]) k = ar[i];
            else k = ar[j];

            water = k * (j-i);
            if(water > mx){
                mx = water;
                woodleft = i;
                woodright = j;
            }
        }
    }

    printf("%d %d\n%lld", woodleft, woodright, mx);
    return 0;
}
