#include <bits/stdc++.h>
using namespace std;

void e(int a, int b) {
    if(a == 0 || b == 0) return ;

    if(b % a == 0) {
        cout << "1/" << b/a;
        return ;
    } 

    if(a % b == 0) {
        cout << a/b; return ;
    }

    if(a > b) {
        cout << a/b << " + "; 
        e(a%b, b);
        return ;
    }

    int k = b/a + 1;
    cout << "1/" << k << " + ";
    e(a*k-b, b*k);

    return ;
}

int main()
{
	int x, y; cin >> x >> y;
    e(x, y);
	return 0;
}
