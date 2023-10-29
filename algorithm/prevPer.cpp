#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    int i = n-1;
    while(i > 0 && v[i-1] <= v[i]) i--;
    if(i <= 0) {
        cout << "no permutation";
        return 0;
    }


    int j = i - 1;
    while(j + 1 < n && v[j + 1] < v[i-1]) j++;
    
    swap(v[i-1], v[j]);
    reverse(v.begin() + i, v.end());

    for(int x : v) cout << x << ' ';
    return 0;
}