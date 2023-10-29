#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

const int N = 1005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char c[N];

    cin.getline(c, N);
    int cnt=0, sp[N], k=0;

    for(int i=0; i<N; ++i){
        if(c[i] == ' '){
           cnt++;
        }else if(cnt!=0){
            sp[k++] = cnt;
            cnt=0;
        }
    }

    string s[N];
    char * pch;
    int j=0;
    pch = strtok(c," ");
    while(pch != NULL){
        s[j++] = pch;
        pch = strtok(NULL, " ") ;
    }

    if(j==1) {
        cout << c;
        return 0;
    }

    for(int i=0; i<j; ++i) {
        int currs = s[i].size();
        swap(s[i][currs-1], s[(i+1)%j][0]);
    }
    for(int i=0; i<j; ++i) {
        cout << s[i];

        for(int k=0; k<sp[i]; ++k) cout << ' ';
    }
    return 0;

}
/// Zemo will get revenge on everyone who oppose him