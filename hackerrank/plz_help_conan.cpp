#include <bits/stdc++.h>
using namespace std;

vector<int> parent[100005];
vector<pair<int,long long>> graph[100005];
priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq2;
long long dist[100005];
bool ispart[100005];
long long dist2[100005];

void dfs(int node, int pa) {
    ispart[node] = 1;
    for (auto it : parent[node]) {
        if (it == pa || it == -1)continue;
        dfs(it,node);
    }
    return;
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long w;
        scanf("%d%d%lld",&x,&y,&w);
        graph[y].push_back({x,w});
    }
    for (int i = 1; i <= n; ++i) {
        dist[i] = LLONG_MAX;
        dist2[i] = LLONG_MAX;
    }
    pq.push({0,t,-1});
    dist[t] = 0;
    // long long finalcall = LLONG_MAX;
    for (;!pq.empty();) {
        long long w;
        int b, pa;
        tie(w,b,pa) = pq.top();
        pq.pop();
        // if (w > finalcall)break;
        if (w > dist[b]) {
            continue;
        }
        if (w <= dist[b]) {
            parent[b].push_back(pa);
        }
        // if (b == s) {
        //     finalcall = dist[b];
        // }
        for (auto it : graph[b]) {
            if (dist[it.first] >= dist[b]+it.second) {
                dist[it.first] = dist[b]+it.second;
                pq.push({dist[it.first],it.first,b});
            }
        }
    }
    dfs(s,-1);
    for (int i = 1; i <= n; ++i) {
        if (ispart[i]) {
            printf("%d ",i);
            pq2.push({0,i});
            dist2[i] = 0;
        }
    }
    printf("\n");
    for (;!pq2.empty();) {
        long long w;
        int b;
        tie(w,b) = pq2.top();
        pq2.pop();
        // printf("%lld %d\n",w,b);
        if (w > dist2[b]) {
            continue;
        }
        for (auto it : graph[b]) {
            if (dist2[it.first] > dist2[b]+it.second) {
                // printf("%d %d <<\n",it.first,b);
                dist2[it.first] = dist2[b]+it.second;
                pq2.push({dist2[it.first],it.first});
            }
        }
    }
    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        int k;
        scanf("%d",&k);
        if (dist2[k] == LLONG_MAX)dist2[k] = -1;
        printf("%lld\n",dist2[k]);
    }
    return 0;
}