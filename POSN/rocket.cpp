#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

const int N = 1e5 + 3;
int a[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);

    int mxh = 0, ans = -1e7;
    for(int i=n-1; i>=0; --i){
        if(a[i] <= mxh) continue;
        mxh = a[i];
        int j=i;
        while(a[j] <= a[i] && j >= 0) --j;

        int k = i-j;
        if(j == 0) k++;
        ans = max(ans, k);
    }

    printf("%d", ans);
    return 0;
}
