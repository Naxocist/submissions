#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
using ll = long long;
string s;
bool choose[10];
int freq[26];
unordered_map<string, int> um;
 
void recur(int n, string c){
	if(n == s.size()) {
		if(um.find(c) == um.end()){
			cout << c << endl;
			um[c]++;
		}
		return ;
	}
 
	for(int i=0; i<s.size(); ++i){
		if(choose[i]) continue;
		choose[i] = true;
		recur(n+1, c+s[i]);
		choose[i] = false;
	}
}
 
 
int fac(int n) {
	int s=1;
	for(int i=1; i<=n; ++i) s*=i;
	return s;
}
 
 
int main() {
	cin >> s;
	for(auto x : s) freq[x-'a']++;
	int f = 1;
	for(int i=0; i<8; ++i) f *= fac(freq[i]);
	printf("%d\n", fac(s.size()) / f);
	sort(s.begin(), s.end());
	
	recur(0, "");
	return 0;
}
