#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; scanf("%d%d", &n, &m);

    deque<int> q;
    for(int i=1; i<=n; ++i) q.push_back(i);

    while(n--) {
        int t = m % q.size(); if(t == 0) t = q.size();
        while(t > 1) q.push_back(q.front()), q.pop_front(), t--;
        printf("%d\n", q.front());
        q.pop_front();
    }
    return 0;
}