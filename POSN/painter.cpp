#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

int main(){
    int n; cin >> n;
    int s = 2*n-1;


    int md = (s+1)/2 - 1;

    for(int i=0; i<s; ++i){
        for(int j=0; j<s; ++j){
            printf("%c ", 'A' + ((abs(md - i) + abs(md - j)) % 26));
        }
        cout << endll;
    }


    return 0;
}
