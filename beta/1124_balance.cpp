#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);

    vector<int> v; int x = n;
    while(x) v.push_back(x % 3), x /= 3;
    v.push_back(0);
    int a = 0, b = 0;
    for(int i=0; i<v.size(); ++i) {
        if(v[i] == 2) a++;
        if(v[i] == 2 || v[i] == 3) {
            v[i+1] ++;
            v[i] = 0;
        }
    }
    int m = 1;
    for(int i=0; i<v.size(); ++i, m*=3) {
        if(v[i]) b += m, a++;
    }
    printf("%d %d", a, b);
    return 0;
}