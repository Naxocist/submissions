#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
	int n, q; scanf("%d %d", &n, &q);
 
	set<int> s;
	s.insert(0);
	s.insert(n);
	multiset<int> d;
	d.insert(n);
	int res = 0;
	while(q--) {
		int x; scanf("%d", &x);
 
		auto t = s.upper_bound(x);
		int a = *t, b = *(--t);
		// printf("%d %d\n", a, b);
		d.erase(d.find(a-b));
		d.insert(a-x);
		d.insert(x-b);
		s.insert(x);
		// for(auto y : d) printf("%d ", y);
		// 	printf("\n");
		printf("%d ", *(--d.end()));
	}
 
	return 0;
}
