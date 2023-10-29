    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n, m; string a, b, z; cin >> m >> n >> a >> b >> z;
        int s = n-1, e = n-1;
        bool c = 0;

        for(int x=0; x < m;) {

            int k = x;
            for(int i=s; i<=e && k < m; ++i, ++k) {
                if(z[i] > a[k] && z[i] > b[k]) 
                    z[i] = max(a[k], b[k]);
                else if(z[i] < a[k] && z[i] < b[k]) 
                    z[i] = min(a[k], b[k]);
            }

            if(s) s--;
            else x++;

            if(c) e--;
            if(x+e-s == m-1) c = 1;
        }

        cout << z;

        return 0;

    }
