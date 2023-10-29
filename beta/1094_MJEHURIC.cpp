#include <bits/stdc++.h>
using namespace std;

int ar[5];

int main() {

    int n = 5;
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);

    while(!is_sorted(ar, ar+n)) {
        for(int i=0; i<n-1; ++i) {
            if(ar[i] > ar[i+1]) {
                swap(ar[i], ar[i+1]);
                for(int j=0; j<n; ++j) printf("%d ", ar[j]);
                printf("\n");
            }
        }
    }

    return 0;
}