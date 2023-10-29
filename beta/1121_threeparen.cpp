#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
char a[N];
int main() {
    int q; cin >> q;
    a[')'] = '('; a[']'] = '['; a['}'] = '{';

    while(q--) {
        string s; cin >> s;

        stack<char> st;
        bool y = 1;
        for(int i=0; i<s.size(); ++i) {
            char c = s[i];

            if(c == ')' || c == ']' || c == '}') {
                if(st.empty() || st.top() != a[c]) {
                    y = 0; break ;
                }
                st.pop();
            }else st.push(c);
        } 

        if(y && st.empty()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}