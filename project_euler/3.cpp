#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const ll N = 836660;
vector<bool> isprime(N+1, true);

int main() {

    // vector<ll> prime;

    // for(ll i=2; i<=N; ++i) {
    //     if(isprime[i]) {
    //         prime.push_back(i);
    //         for(ll j=i*i; j<=N; j+=i) {
    //             isprime[j] = false;
    //         }
    //     }
    // }


    // reverse(prime.begin(), prime.end());
    // for(ll x : prime) {
    //     if(600851475143 % x == 0) {
    //         printf("%lld", x);
    //         return 0;
    //     }
    // }

    ll x = 600851475143 ;
    int res = 2, factor = 2, mx = sqrt(600851475143);

    while(factor <= mx) {
        if(x % factor == 0) {
            res = factor;
            while(x % factor == 0) {
                x /= factor;
            }
        }
        factor ++;
    }

    printf("%d", res);
    return 0;
}