#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);

    string s = "Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you";

    vector<string> v;
    string t;
    for(char &c : s) {
        if(c == ' ') {
            v.push_back(t);
            t = ""; continue ;
        }
        t += c;
    }
    v.push_back(t);

    while(k--) {
        cout << v[n-1] << ' ';
    }
    return 0;
}