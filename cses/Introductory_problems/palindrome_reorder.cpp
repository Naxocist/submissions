#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
 
int main() {
	
	string s; cin >> s;
 
	unordered_map<char, int> um;
	deque<char> f, b;
	
	for(auto c : s){
		um[c]++;
		if(um[c] == 2){
			um[c] = 0;
			b.push_front(c);
			f.push_back(c);
		}
	}
	int cnt = 0;
	char m;
	bool chk = false;
	for(auto x : um){
		if(x.second == 1){
			cnt++;
			m = x.first;
			chk = true;
		}
	}
 
	if(cnt <= 1) {
		for(auto x : f) printf("%c", x);
		if(chk)printf("%c", m);
		for(auto x : b) printf("%c", x);
	}
	else printf("NO SOLUTION");
	
 
	return 0;
}
