#include <bits/stdc++.h>
using namespace std;

using vi = vector<int> ;

unordered_map<char, vi> um = {
    {'F', {4, 1, 3, 6, 5, 2}}, 
    {'B', {2, 6, 3, 1, 5, 4}},
    {'L', {5, 2, 1, 4, 6, 3}},
    {'R', {3, 2, 6, 4, 1, 5}},
    {'C', {1, 5, 2, 3, 4, 6}},
    {'D', {1, 3, 4, 5, 2, 6}}
} ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int q; cin >> q;
    
    while(q--) {
        string s; cin >> s;
        vi dice = {1, 2, 3, 5, 4, 6}, tmp(6);

        for(auto c : s) {
            for(int i=0; i<6; ++i) {
                tmp[i] = dice[um[c][i] - 1];
            }
            
            dice = tmp;
        }
        
        cout << dice[1] << ' ';
    }
    
    return 0;
}

/*
3
D
FFBB
BBFFR
*/