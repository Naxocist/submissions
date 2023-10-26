#include <bits/stdc++.h>

using namespace std;

#define ll long long

using pi = pair<int, int>;

const int N = 8e6 + 3;
bool notprime[N];
vector<int> prime;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    
	int n; cin >> n;
	int cnt=0;
	

	for(int i=2; i*i < N; ++i){
		if(!notprime[N]){
			
			for(int j=i*i; j<N; j+=i) notprime[j] = true;
		}

	}
	for(int i=2; i<=N; ++i) if(!notprime[i]) prime.push_back(i);

	cout << prime[n-1];
	return 0;

}
