#include <bits/stdc++.h>
#define endll '\n'
using namespace std;
using pi = pair<int, int>;
using pii = pair<int, pi>;

const int N = 1e5 + 3;
int seats[N];

int main(){
    int n; scanf("%d", &n);

    vector<pii> people;

    for(int i=1; i<=n; ++i){
        seats[i] = -1;
        int in, out; scanf("%d %d", &in, &out);
        if(in < 1700 || in > 2300 || out < 1700 || out > 2300 || in >= out) continue;

        // sort : time -> 0 -> 1 -> id
        people.push_back({out, {0, i}}); // exit festival
        people.push_back({in, {1, i}}); // enter festival

    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<=n; ++i) pq.push(i);

    sort(people.begin(), people.end());

    for(auto p : people){

        int action = p.second.first, id = p.second.second;

        if(action == 1){
            seats[id] = pq.top();
            pq.pop();
        }else{
            pq.push(seats[id]);
        }
    }

    for(int i=1; i<=n; ++i) printf("%d\n", seats[i]);
    return 0;
}
