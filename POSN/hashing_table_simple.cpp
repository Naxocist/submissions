#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

const int N = 1e6+3;
list<int> a[N];
int input[N];

int main() {
    
    int s, n; cin >> s >> n;

    for(int i=0; i<n; ++i) cin >> input[i];
    unordered_map<int, list<int>> umap; // <index, value>

    while(s/2 < n) s*=2;

    for(int i=0; i<n; ++i){
        int r = input[i]%s;
        umap[r].push_back(input[i]);
    }

    
    for(int i=0; i<s; ++i){
        if(umap.find(i) != umap.end()) {
            for(int &x : umap[i]) cout << x << ' ';
        }else cout << "empty";
        cout << endll;
    }
    
    return 0;
}
