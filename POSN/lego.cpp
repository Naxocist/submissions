#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


int a[105];

int main() {

    int n; cin >> n;
    int avg=0;
    for(int i=0 ; i<n; ++i){
        cin >> a[i];
        avg += a[i];
    }

    avg /= n;
    int s = 0;
    for(int i=0; i<n; ++i) if(a[i] > avg) s += a[i]-avg;

    cout << s;
    return 0;
}

