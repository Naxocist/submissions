#include <bits/stdc++.h>
using namespace std;


const int N = 100 + 3;
char ar[N][N];


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int n; cin >> n;
	int H = -1e9, L = -1e9;

	for(int i=0; i<100; ++i){
		for(int j=0; j<100; ++j) ar[i][j] = '.';
	}

	while(n--){
		int s, h; cin >> s >> h;
		s--; // index 

		H = max(H, h-1);
		L = max(L, s + h*2);
		for(int j=0; j<h; ++j){
			int st = s + j, ed = st + (h-j)*2 - 1;

			if(ar[j][st] == '.') ar[j][st] = '/';
			else if(ar[j][st] == '\\') ar[j][st] = 'v';

			if(ar[j][ed] == '.') ar[j][ed] = '\\';
			else if(ar[j][ed] == '/') ar[j][ed] = 'v';

			for(int k=st+1; k<ed; ++k) ar[j][k] = 'X';
		}

	}

	for(int i=H; i>=0; --i){
		for(int j=0; j<L; ++j){
			cout << ar[i][j];
		}
		cout << '\n';
	}

}