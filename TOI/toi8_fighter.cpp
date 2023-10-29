#include <bits/stdc++.h>
#define endll '\n'
typedef long long ll;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int p; cin >> p;

    ll atk;
    int streako=0, streake=0, o=p, e=p;
    while(cin >> atk){

        if(atk&1){
            streake = 0;
            streako++;
            e -= 1 + (streako >= 3 ? 2 : 0);
        }else{
            streako = 0;
            streake++;
            o -= 1 + (streake >= 3 ? 2 : 0);
        }

        if(o <= 0) {
            cout << "0\n" << atk;
            return 0;
        }
        if(e <= 0) {
            cout << "1\n" << atk;
            return 0;
        }
    }
    return 0;
}
