#include <bits/stdc++.h>
using namespace std;
double n, i, z, p, in, a, b, c=2e18;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	scanf("%lf", &n);
	for(i=1000, z = 0; i<=15000; i+=500, z++) {
		for(p=74; p<=144; p++) {
			in = (p * ((100 - (0.8569 * exp(0.09 * (p-100))))*i/100)) - (n + i*(100-z));
			if(in > 0 and in < c) {
				a = i, b = p, c = in;
			}
		}
	}
	printf("%.0lf\n%.0lf\n%.2lf", a, b, c);
	return 0;
}