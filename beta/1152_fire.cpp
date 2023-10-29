#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int ar[N][N];

int main() {

	int n; scanf("%d", &n);

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) scanf("%d", &ar[i][j]);
	}

	priority_queue<int> pq;
	int res = 0;

	for(int k = n-1; k>=0; --k) {
		for(int i=n-1, j=k; j<n; i--, j++) pq.push(ar[i][j]);	
		res += pq.top(); pq.pop();
	}


	for(int k = n-2; k>0; --k) {
		for(int i=k, j=0; i>=0; i--, j++) pq.push(ar[i][j]);	
		res += pq.top(); pq.pop();
	}

	printf("%d", res);
	return 0;

}