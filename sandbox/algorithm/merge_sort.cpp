#include <bits/stdc++.h>
using namespace std;

int ar[1005], t[1005];
void mergeSort(int l, int r) {
    if(l >= r) return ;
    int md = l + (r - l)/2;
    mergeSort(l, md);
    mergeSort(md+1, r);

    int a = l, b = md+1, i = l;
    while(a <= md && b <= r) {
        if(ar[a] < ar[b]) t[i++] = ar[a++];
        else t[i++] = ar[b++];
    }

    while(a <= md) t[i++] = ar[a++];
    while(b <= r) t[i++] = ar[b++];

    for(int j=l; j<=r; ++j) ar[j] = t[j];

    return ;
}


int main() {
    int n; scanf("%d", &n);

    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);

    mergeSort(0, n-1);

    for(int i=0; i<n; ++i) printf("%d ", ar[i]);
    return 0;
}

/*
5
2 3 1 5 4
*/
