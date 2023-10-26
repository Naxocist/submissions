#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

// find number at index n in "0123456789101112131415..."

int main() {
	int n; scanf("%d", &n);

	if(n >= 0 && n<=10){
		printf("%d", n-1);
		return 0;
	}

	int cnt = 11;
	for (int i = 10; i <= n; i++) // iterative solution
	{
		int k = i, d = 0;
		while(k) k/=10, d++;
		d = pow(10, d-1);
		k = i;
		
		while(d){
			int x = k / d;
			if(cnt == n){
				printf("%d", x);
				return 0;
			}
			
			k -= x*d;
			d /= 10;
			cnt++;
		}
	}
	
	return 0;
}
