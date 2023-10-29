#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int ar[N];

int main() {

    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]);
    sort(ar, ar+n);

    if(n >= 3 && ar[0] + ar[1] <= ar[n-1]) printf("yes");
    else printf("no");
    return 0;
}