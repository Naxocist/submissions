#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


void fillzero(string &a, int mx){
    reverse(begin(a), end(a));
    while(a.size() != mx+1){
        a+="0";
    }
    reverse(begin(a), end(a));
}

string add(string a, string b){
    if(a == "0") return b;
    if(b == "0") return a;

    int mx = max(a.size(), b.size());
    fillzero(a, mx); fillzero(b, mx);
    string r;
    int carry = 0;
    for(int i=mx; i>=0; --i){
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        r += (sum%10) + '0';
        carry = sum/10;
    }
    reverse(begin(r), end(r));

    if(r[0] == '0') r = r.substr(1, mx);

    return r;
}

string subtract(string a, string b){
    int mx = max(a.size(), b.size()) - 1;
    fillzero(a, mx); fillzero(b, mx);

    if(a == b){
        cout << "0";
        return " ";
    }


    bool neg = false;
    if(b[0] > a[0]) {
        swap(b, a);
        neg = true;
    }

    string r;
    int borrow = 0;
    for(int i=mx; i>=0; --i){

        int x=a[i]-'0'-borrow, y=b[i]-'0';
        int tmp = x;
        if(x < y) x+=(i ? 10 : 0);
        int diff = abs(x-y);
        r += diff + '0';
        borrow = (tmp<y);
    }

    reverse(begin(r), end(r));
    if(r[0] == '0') r = r.substr(1, mx);
    if(neg) cout << "-";
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b, c;

    cin >> a >> b >> c;

    cout << subtract(add(a, b), c);
    return 0;
}

/*
234 543 2000
*/
