#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int res[40][40], f, s, t;
vector<int> parent;

void augment(int v, int bottleNeck){
	
	if(v == s){ // found start node
		f = bottleNeck; return ;
	}

	if(parent[v] != -1){
		augment(parent[v], min(bottleNeck, res[parent[v]][v])); // reverse to start node by parent
		res[parent[v]][v] -= f;
		res[v][parent[v]] += f;
	}
}


int main(){
	int n; scanf("%d %d %d", &n, &s, &t);

	for(int i=0; i<n; ++i){
		int m; scanf("%d", &m);

		for(int j=0; j<m; ++j){
			int v, w; scanf("%d %d", &v, &w);
			res[i][v] = w;
		}
	}

	int mf = 0;
	while(1){
		f = 0;
		vector<int> dist(40, INF);
		dist[s] = 0;
		parent.assign(40, -1);

		queue<int> q; q.push(s);
		while(!q.empty()){ // breadth first search
			int u = q.front(); q.pop();

			if(u == t) break;
			for(int v=0; v < 40; v++){
				if(res[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1;
					q.push(v);
					parent[v] = u; // set parent for every node
				}
			}
		}
		augment(t, INF); // maximize flow
		if(f == 0) break;
		mf += f;
	}

	printf("%d", mf);
	return 0;
}