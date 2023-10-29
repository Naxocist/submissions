#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using pii = pair<pi, char>;

int main(){
    int t; scanf("%d", &t);

    for(int k=1; k<=t; ++k){
        int n; scanf("%d", &n);
        vector<pair<pi, int>> v;
        int s, e;

        for(int i=0; i<n; ++i){
            scanf("%d %d", &s, &e);
            v.push_back({{s, e}, i});
        }

        sort(v.begin(), v.end());

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({{v[0].first.second, v[0].first.first}, 'C'});

        char ans[1005];
        ans[v[0].second] = 'C';

        for(int j=1; j<n; ++j){
            s = v[j].first.first; e = v[j].first.second;
            int index = v[j].second;

            char c = pq.top().second;
            if(s >= pq.top().first.first)  pq.pop();
            else c = (c == 'C' ? 'J' : 'C');

            ans[index] = c;
            pq.push({{e, s}, c});

        }

        cout << "Case #" << k << ": ";
        if(pq.size() > 2) cout << "IMPOSSIBLE";
        else for(int q=0; q<n; ++q) cout << ans[q];
        
        cout << "\n";
    }
    return 0;
}

/*
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
*/