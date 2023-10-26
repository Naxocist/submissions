#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

const int N = 1e6 + 3;
pair<int, int> a[N];

int main()
{
    int n, t; scanf("%d%d", &n, &t);
    for(int i=1; i<= n; ++i){
        a[i].first = i-1;
        a[i].second = i+1;
        if(i == 1) a[i].first = -1;
        if(i == n) a[i].second = -1;
    }

    while(t--){
        int l, r; scanf("%d%d", &l, &r);
        a[a[l].first].second = a[r].second;
        a[a[r].second].first = a[l].first;
        int x = a[a[r].second].first, y = a[a[l].first].second;

        if(x == -1) printf("* ");
        else printf("%d ", x);
        if(y == -1) printf("*\n");
        else printf("%d\n", y);
    }
    return 0;
}
