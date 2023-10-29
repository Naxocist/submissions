#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;

int main() {

	int n, m, k; scanf("%d%d%d", &n, &m, &k);

	vector<int> prev(m+1, 0);
	int res = 0;

	for(int i=1; i<=m; ++i) {
		scanf("%d", &prev[i]);
		res = max(res, prev[i]);
	}

	for(int i=2; i<=n; ++i) {
		vector<int> t(m+1);
		deque<int> dq;
		int r = 1;
		for(; r<k+1; ++r) {
			int y = prev[r];
			while(dq.size() && prev[dq.back()] < y) dq.pop_back();
			dq.push_back(r);
		}
		for(int j=1; j<=m; ++j) {
			int x; scanf("%d", &x);

			
			while(r <= m && dq.size() && prev[dq.back()] < prev[r]) dq.pop_back();
			while(dq.size() && r - dq.front() > 2 * k ) dq.pop_front();

			dq.push_back(r);
			
			int d = prev[dq.front()] + x;
			t[j] = d;

			if(i == n) res = max(res, d);

			r++;
		}

		prev = t;
	}
	printf("%d", res);
	return 0;
}