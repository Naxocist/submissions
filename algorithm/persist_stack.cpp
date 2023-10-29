#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

vector<int> tops = {-1};
vector<pi> nodes;
int version = 0;

int ppush(int val) {
    nodes.pb(val, tops.size() - 1);
    tops.pb(nodes.size() - 1);
    return ++version;
}

int ppop() {
    int t = tops[version];
    tops.pb(nodes[t].second);
    return ++version;
}

int ptop(int ver) {
    return nodes[tops[ver]].first;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ppush(3);
    ppush(4);
    ppop();
    cout << ptop(3) << '\n';
    return 0;
}
