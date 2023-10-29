#include <bits/stdc++.h>
using namespace std;
const int n = 7;
bool vis[10][10];
string s;
int res = 0;
 
bool ok (int i, int j) {
	return (i >= 1 and j >= 1 and i <= n and j <= n and !vis[i][j]);
}
 
void f(int i, int j, int k) {
	if(i == n and j == 1) {
		if(k == s.size()) res++;
		return ;
	}
	// cout << i << ' ' << j << endl;
 
	if((i == 1 || i == n) and j>1 and j<n and !vis[i][j-1] and !vis[i][j+1]) return ;
	if((j == 1 || j == n) and i>1 and i<n and !vis[i+1][j] and !vis[i-1][j]) return ;
	if(j>1 and j<n and vis[i+1][j] and vis[i-1][j] and !vis[i][j-1] and !vis[i][j+1]) return ;
	if(i>1 and i<n and vis[i][j+1] and vis[i][j-1] and !vis[i+1][j] and !vis[i-1][j]) return ;
	vis[i][j] = 1;
	char c = s[k];
	if((c == 'U' || c == '?') and ok(i-1, j)) f(i-1, j, k+1);
	if((c == 'D' || c == '?') and ok(i+1, j)) f(i+1, j, k+1);
	if((c == 'L' || c == '?') and ok(i, j-1)) f(i, j-1, k+1);
	if((c == 'R' || c == '?') and ok(i, j+1)) f(i, j+1, k+1);
	vis[i][j] = 0;
	return ;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	f(1, 1, 0);
	cout << res;
	return 0;
}