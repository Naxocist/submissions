#include <bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(nullptr);
    int q; scanf("%d", &q);

    priority_queue<int> pq;
    while(q--) {
        char c; scanf(" %c", &c);
        if(c == 'P') {
            int x; scanf("%d", &x);
            pq.push(x);
        }else {

            if(pq.size()) {
                cout << pq.top(); pq.pop();
            }else cout << -1;
            cout << '\n';
        }
    }
    return 0;
}