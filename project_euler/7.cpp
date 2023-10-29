#include <bits/stdc++.h>
using namespace std;

const int N = 8e6 + 3;
using ll = long long int;


bool checkprime(int x) {
    if(x < 2) return false;
    if(x < 4) return true;
    if(x % 2 == 0) return false;
    if(x % 3 == 0) return false;

    ll lim = sqrt(x);
    // all prime can be written = 6k +- 1
    ll f = 5; 
    while(f <= lim) {
        if(x % f == 0) return false; // 6k - 1;
        if(x % (f + 2) == 0) return false; // 6k + 1;

        f+=6;
    }

    return true;
}

int main() {

    int n = 10001;
    int res = 1, cnt = 1;
    do {
        res += 2;
        if(checkprime(res)) cnt++;

    }while(cnt < n);

    printf("%d", res);

    // vector<bool> isprime(N, true);
    // vector<ll> prime;
    // for(ll i=2; prime.size() < n; ++i) {
    //     if(!isprime[i]) continue ;
    //     printf("%d\n", i);
    //     prime.push_back(i);

    //     for(ll j=i*i; j<=N; j+=i) {
    //         isprime[j] = false;
    //     }
    // }

    // printf("%d", prime.back());
    return 0;
}