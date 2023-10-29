#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int pat[N];

int main() {

    string s, p;
    s = "aaaaaa";
    p = "aaa";


    int i = 0;
    for(int j=1; j<p.size();) {
        if(p[i] == p[j]) {
            pat[j] = i + 1;
            j++; i++;  
        }else {
            if(i) {
                i = pat[i-1];
            }else {
                pat[j] = 0;
                j++;
            }
        }
    }

    // for(int h=0; h<p.size(); ++h) cout << pat[h] << " ";
    int x = 0, y = 0, res = 0;

    while(x < s.size() && y < p.size()) {
        if(s[x] == p[y]) {
            x++, y++;
            if(y == p.size()) {
                cout << "FOUND AT : " << res;
            }
        }
        else {
            int k = y;
            if(y) y = pat[y-1];
            else x++;

            res = x;
        }
    }

    return 0;
}
