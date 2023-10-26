#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using ll = long long;

const int N = 5e6 + 3;
int ar[N];

int main(){

    int n, k; scanf("%d%d", &n, &k);

    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);
    ar[0] = ar[n+1] = -1;

    vector<int> v;
    for(int i=1; i<=n; ++i){
        if(ar[i] > ar[i-1] && ar[i] > ar[i+1]){
            v.push_back(ar[i]);
        }
    }

    if(v.empty()){
        printf("-1");
        return 0;
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
  
    if(v.size() >= k) {
        for(int i=v.size()-1; i>=0 && k; --i, --k) printf("%d\n", v[i]);
    }else{
        for(int i=0; i<v.size(); ++i) printf("%d\n", v[i]);
    }

    return 0;
}
