#include <bits/stdc++.h>
using namespace std;


int main() {
    string s, ans;
    cin >> s;

    for(auto c : s){
        bool np = true;

        for(int i=0; i<ans.size(); ++i){
            if(ans[i] >= c) {
                ans[i] = c;
                np = false;
                break;
            }
        }

        if(np) ans.push_back(c);
    }

    cout << ans << '\n' << ans.size();
    return 0;
}

/*
ABAC
*/
