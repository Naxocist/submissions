#include <bits/stdc++.h>
using namespace std;


#define ll long long

using pi = pair<int, int>;

struct d {
    int x, h;
};

int main() {

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	d d[n+3];

	for(int i=0; i<n; ++i) {
        int x, h; cin >> x >> h;
        d[i] = {x, h};
    }

	char di = 'L';
	int mx = -1e9, s = 0;

    for(int i=0; i<n;){
        int k = i;
        int range = d[k].x + d[k].h;
        
        while(1){
            k++;    
            if(k >= n || range <= d[k].x) break;

            range = max(range, d[k].x + d[k].h);
        }
        // k = next to the latest fall domino
        if(k-i > mx){
            mx = k-i;
            s = i+1;
            di = 'R';
        }

        i = k;
    }

    for(int i=n-1; i>=0;){
        int k = i;
        int range = d[k].x - d[k].h;

        while(1){
            k--;
            if(k < 0 || range >= d[k].x) break;

            range = min(range, d[k].x - d[k].h);
        }

        if(i - k > mx || (i - k == mx && i < s)){
            mx = i-k;
            s = i+1;
            di = 'L';
        }

        i = k;
    }

	cout << s << ' ' << di;

	return 0;

}