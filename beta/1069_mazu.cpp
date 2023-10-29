#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);
    stack<char> st;
    while(n--) {
        char c; scanf(" %c", &c);

        if(st.size() && st.top() == c) {
            st.pop();
        }else st.push(c);
    }

    if(st.empty()) {
        printf("0\nempty");
        return 0;
    }

    printf("%d\n", st.size());
    while(st.size()) {
        printf("%c", st.top());
        st.pop();
    }
    return 0;
}