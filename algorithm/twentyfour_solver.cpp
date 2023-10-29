#include <bits/stdc++.h>
using namespace std;

double ar[4];
bool choose[4];
char o[] = {'+', '-', '*', '/'};
int n;

double f(double a, double b, int x) {
    if(x == 0) return a + b;
    else if(x == 1) return a-b;
    else if(x == 2) return a*b;
    
    return a/b;
}

void solve(int k, double s, string res) {
    if(k == n) {
        if(s == 24) cout << res << '\n';
        
        return ;
    }
 
    for(int i=0; i<n; ++i) {
        if(choose[i]) continue ;
        choose[i] = 1;
        for(int j=0; j<n; ++j) {
            // string t = res;
            // res  = res + o[j] + (ar[i] + '0');
            solve(k+1, f(s, ar[i], j), res + " " + char(o[j]) + " " + to_string(int(ar[i])) + ")");
        }
        choose[i] = 0;
    }
    
    return ;
}

int main()
{
    n = 4;
    for(int i=0; i<n; ++i) cin >> ar[i];

    for(int i=0; i<n; ++i) {
        choose[i] = 1;
        solve(1, ar[i], "(((" + to_string(int(ar[i])));
        choose[i] = 0;
    }

    return 0;
}