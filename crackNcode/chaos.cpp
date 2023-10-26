#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 2e5 + 3, M = 1e5 + 3;
int dsu[M];
pi edge[N];
int group;
stack<int> st;

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    
    if(u == v) return ;
    
    dsu[u] = v;
    group--;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	group = n;
	for(int i=1; i<=n; ++i) dsu[i] = i;
	
	for(int i=1; i<=m; ++i) {
	    scanf("%d%d", &edge[i].first, &edge[i].second);
	}
	
	vector<int> v(m);
	for(int i=0; i<m; ++i) scanf("%d", &v[i]);
	
	for(int i=m-1; i>=0; --i) {
	    st.push(group);
	    un(edge[v[i]].first, edge[v[i]].second);
	}
    
	while(st.size()) {
	    printf("%d\n", st.top());
	    st.pop();
	}
	return 0;
}

/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4
6
5
4
3
2
1
*/