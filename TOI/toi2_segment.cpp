#include <bits/stdc++.h>
using namespace std;

const int N = 13;
using ll = long long int;
string number[2][N];

int f(string s) {
    if(s == "     |  |") return 1;
    else if(s == " _  _||_ ")return 2;
    else if(s == " _  _| _|") return 3;
    else if(s == "   |_|  |") return 4;
    else if(s == " _ |_  _|") return 5;
    else if(s == " _ |_ |_|") return 6;
    else if(s == " _   |  |") return 7;
    else if(s == " _ |_||_|") return 8;
    else if(s == " _ |_| _|") return 9;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string s; getline(cin, s);
    for(int k=0; k<2; ++k) {
        for(int i=0; i<3; ++i) {
            getline(cin, s);
            for(int j=0; j<(int)s.size(); ++j) {
                if((j+1) % 4 == 0) continue ;
                number[k][j/4] += s[j];
            }
            
        }
    }

    ll x = 0, y = 0;
    for(int i=0; i<n; ++i) {
        x*=10;
        x += f(number[0][i]);
    }
    
    for(int i=0; i<m; ++i) {
        y*=10;
        y += f(number[1][i]);
    }
    cout << x + y;
    return 0;
}

/*
4 2
                 
  | |_|   | |_|
  |   |   |   |
                 
|_|   |
  |   |
*/