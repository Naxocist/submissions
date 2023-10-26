#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int state[N];

int main() {

	int n; scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &state[i]);
	}

	for(int i=1; i<=n; ++i) {
		if(state[i] == -1 || i < 1) continue ;

		if(state[i] == 1) {
			printf("%d ", i);
			state[i] = -1;
			if(state[i-1] >= 0) state[i-1] ^= 1;
			if(state[i+1] >= 0) state[i+1] ^= 1;
		}
		if(state[i-1] == 1) i-=2;
	}

	return 0;
}