#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
 
const int N = 205, M = 2e5 + 10;
int counting[N], tmp[M];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n, d; cin >> n >> d;
	
	vi v;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		v.push_back(x);
	}

	int cnt = 0, sz = v.size();
    
    for(int i=0; i<d; ++i) counting[v[i]]++;
    
    
    for(int i=d; i<sz; ++i){
        int x = v[i];
        
        double md;
        int idx=0;
 
        for(int c=0; c<=200; ++c){
            int ct = counting[c];
            while(ct--){
                tmp[idx++] = c;
                if(idx > d/2) break;
            }
            if(idx > d/2) break;
        }
       
        md = (d&1 ? tmp[d/2] : (tmp[d/2] + tmp[d/2-1]) / 2.0);
        if(x >= md*2){
            cnt++;
        }
        
        counting[v[i-d]]--;
        counting[v[i]]++;
    }
    
    
	cout << cnt;
	return 0;
}
