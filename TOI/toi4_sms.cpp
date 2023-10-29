#include <bits/stdc++.h>
#define endll '\n'

using namespace std;
using pi = pair<int, int>;
using pii = pair<int, pi>;
stack<char> ans;

void press(int btn, int r){

    if(btn == 1) {
        if(ans.empty()) return ;
        while(r--) {
            ans.pop();
            if(ans.empty()) return ;
        }
    }

    else if(btn <= 6){
        btn = ((btn-2)*3) + ((r-1)%3);
        ans.push(btn + 'A');
    }

    else if(btn == 7){
        btn = ((r-1)%4);
        ans.push(btn + 'P');
    }

    else if(btn == 8){
        btn = ((r-1)%3);
        ans.push(btn + 'T');
    }

    else if(btn == 9){
        btn = ((r-1)%4);
        ans.push(btn + 'W');
    }
}

int main(){

    int n; scanf("%d", &n);
    int st, m; scanf("%d%d", &st, &m);

    press(st, m);
    while(--n){
        int h, v; scanf("%d%d%d", &h, &v, &m);
        st += h;
        st += v*3;
        press(st, m);
    }

    if(ans.empty()){
        printf("null");
        return 0;
    }

    stack<char> rev;
    while(!ans.empty()){
        rev.push(ans.top());
        ans.pop();
    }

    while(!rev.empty()){
        printf("%c", rev.top());
        rev.pop();
    }
    return 0;
}

