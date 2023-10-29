#include <bits/stdc++.h>
#define endll '\n'
typedef long long ll;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<string> v;
    v.push_back("");

    while(n--){
        int c, pos; cin >> c;
        string s, curr = v.back();
        if(c == 1) {
            cin >> s;
            curr += s;
            cout << curr << endll;
            v.push_back(curr);
        }
        else if(c == 2) {
            cin >> pos;
            curr = curr.substr(0, curr.size()-pos);
            cout << curr << endll;
            v.push_back(curr);
        }
        else{
            v.pop_back();
            curr = v.back();
            cout << curr << endll;
        }

    }
    return 0;
}

/*
5
1 abcde
2 2
1 fg
1 h
3
*/
