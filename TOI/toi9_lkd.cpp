#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, string>;
const int N = 5;
vector<pi> adj[N];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    adj[1].emplace_back(1, "00"); adj[2].emplace_back(1, "11"); adj[3].emplace_back(2, "10"); adj[4].emplace_back(4, "10");
    adj[1].emplace_back(3, "11"); adj[2].emplace_back(3, "00"); adj[3].emplace_back(4, "01"); adj[4].emplace_back(2, "01");
    
    vector<string> v(n); 
    for(int i=0; i<n; ++i) cin >> v[i];
    int state = 1;
    string res;
    for(int j=v.size()-1; j>=0; --j) { 
        string s = v[j];

        bool ok = s.size() >= 16;
        int t = 0, k = 0, i = s.size()-2;
        for(int i=s.size()-2; i>=0; i-=2){
            if(ok) t |= ((state % 2 == 0) << k), k++;
            string c = s.substr(i, 2);
            for(auto x : adj[state]) {
                if(x.second != c) continue ;
                state = x.first;
            }
        }

        if(ok) res = char(t) + res;
    }
    
    cout << res;
    return 0;
}