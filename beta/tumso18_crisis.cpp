#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, q; scanf("%d%d%d", &n, &m, &q);

	vector<int> bio(n+1), his(m+1);
	for(int i=1; i<=n; ++i) scanf("%d", &bio[i]), bio[i] += bio[i-1];
	for(int i=1; i<=m; ++i) scanf("%d", &his[i]), his[i] += his[i-1];

	while(q--) {

		int a, b, c, d, k; scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);

		int l = 1, r = 2e9;

		int res = 0;
		while(l <= r) {
			int md = l + (r - l)/2;
			auto t1 = upper_bound(bio.begin() + a, bio.begin() + c + 1, md + bio[a-1]);
			auto t2 = upper_bound(his.begin() + b, his.begin() + d + 1, md + his[b-1]);


			int books = (t1 - (bio.begin() + a)) + (t2 - (his.begin() + b));

			if(books >= k) {
				res = md;
				r = md - 1;
			}else {
				l = md + 1;
			}
		}

		printf("%d\n", res);
	}
	return 0;
}