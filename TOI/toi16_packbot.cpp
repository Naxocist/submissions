#include <bits/stdc++.h>
using namespace std;

stack<int> n, op;

void calc() {
    int x = n.top(); n.pop();
    x += n.top(); n.pop();

    int o = op.top(); op.pop();

    if(o == 1) x += x * 0.04;
    else if(o == 2) x += x * 0.08;
    else x += x * 0.16;

    n.push(x);
}

int main() {

    string s; cin >> s;
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') {
            n.push(20); continue ;
        }

        if(c == '[') op.push(-1);
        else if(c == ']') {
            while(op.size() && op.top() != -1) calc(); 
            op.pop();
        }
        else {
            while(op.size() && op.top() >= c - '0') calc();
            op.push(c - '0');
        }
    }

    while(op.size()) calc();

    cout << n.top();
}