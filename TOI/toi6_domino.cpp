#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> v;
void f(int n) {
	if(n < 0) return ;
	if(n == 0) {
		for(auto x : v) {
			if(x == 1) printf("--\n");
			else printf("||\n");
		}
		printf("E\n");
		return ;
	}
	v.pb(1); f(n-1); v.pop_back();
	v.pb(2); f(n-2); v.pop_back();
}
int main() {
	int n; scanf("%d", &n);
	f(n);
}
