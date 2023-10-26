#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


int main() {

    list<char> l;
    string s; cin >> s;

    bool back = true;
    list<char>::iterator it = l.end();

    for(char c : s){
        if(c == '[') it = l.begin();

        else if(c == ']') it = l.end();

        else l.insert(it, c);

    }

    for(auto it : l) cout << it;

    return 0;
}
