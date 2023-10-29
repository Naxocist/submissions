#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m; scanf("%d%d", &n, &m);
	vector<int> v(m);

	int mx = 0;
	for(int i=0; i<m; ++i) scanf("%d", &v[i]), mx = max(mx, v[i]);

	int l = 1, r = 150000;
	while(l < r) {
		int md = l + (r - l)/2;

		int cable = 0, curr = md;
		bool ok = (md >= mx);

		for(int x : v) {
			if(curr + x > md) cable++, curr = x;
			else curr += x;
		}
		if(cable <= n && ok) r = md;
		else l = md + 1;
	}

	printf("%d", l);
	return 0;
}