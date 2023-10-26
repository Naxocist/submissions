#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


int main() {
    long long n, cost=0; cin >> n;

    vector<int> v;
    for(int i=0; i<n; ++i){
        int x; scanf("%d", &x);
        v.push_back(x);
    }

    priority_queue<int, vector<int>, greater<int>> pq(begin(v), end(v));

    while(1){

        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int k = a + b;
        cost += k;
        if(pq.empty()) break;
        pq.push(k);
    }

    cout << cost;
    // cout << k + sum;

    return 0;
}
